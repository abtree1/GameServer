#include "stdafx.h"
//#############################################
CLoadIds::CLoadIds() {
	char buff[1024];
	sprintf_s(buff, 1024, "SELECT pid FROM userbase WHERE pserverid = %d ORDER BY pid DESC LIMIT 1",
		gConfigMgr->GetSettingValue<INT>(SERVERID));
	mSqls.push_back(buff);
}

void CLoadIds::Run() {
	//先把对象取出来
	CIdentityImpl* ids = dynamic_cast<CIdentityImpl*>(gIdentify);
	map<string, u32>& idmap = ids->GetAllIds();
	//读取playerid
	mpResult = mpStmt->executeQuery(mSqls[0].c_str());
	u32 serverid = gConfigMgr->GetSettingValue<INT>(SERVERID);
	CIdentifyKey key;
	key.set_type(EID_PlayerId);
	key.set_ivalue(serverid);
	if (mpResult && mpResult->next()) {
		idmap[key.SerializeAsString()] = mpResult->getInt("pid");
	}
	else {
		idmap[key.SerializeAsString()] = serverid * PLAYER_MAX_COUNT;
	}
}

void CLoadIds::Finish() {
	//设置加载完成
	gIdentify->LoadFinish();
}
//#############################################
CSaveTimerTask::CSaveTimerTask() {
	//获取存储的sqls
	CTimerTaskMgr::GetInstance()->SaveToDB(mSqls);
}

void CSaveTimerTask::Run() {

}

void CSaveTimerTask::Finish() {

}
//#############################################

CLoadTimerTask::CLoadTimerTask() {
	//查询所有记录
	mSqls.push_back("SELECT * FROM `g_timertask`");
}

void CLoadTimerTask::Run() {
	mpResult = mpStmt->executeQuery(mSqls[0]);
	while (mpResult && mpResult->next()) {
		//解析每一个timertask
	}
}

void CLoadTimerTask::Finish() {

}
//#############################################
CPrepareLogin::CPrepareLogin(string& account, u32 serverid, CSession* session)
	: mServerId(serverid)
	,mpSession(session){
	char buff[1024];
	sprintf_s(buff, 1024, "SELECT pid FROM userbase WHERE paccount = '%s' AND pserverid = %d;",
		account.c_str(), serverid);
	mSqls.push_back(buff);
}

void CPrepareLogin::Run() {
	mpResult = mpStmt->executeQuery(mSqls[0].c_str());
	if (mpResult && mpResult->next()) {
		mHasPlayer = true;
		mPlayerId = mpResult->getInt("pid");
	}
	mpResult->close();
	mpResult = nullptr;
}

void CPrepareLogin::Finish() {
	//如果已经有玩家 执行玩家加载操作
	if (mHasPlayer) {
		gDBLoadMgr->AddTask(new CLoadPlayer(mPlayerId, mpSession));
		return;
	}
	//如果还没有玩家 执行玩家创建操作
	if (mpSession)
		mpSession->Send(NET_S2C_CreateRole, nullptr);
}
//#############################################
CCreateRole::CCreateRole(u32 pid, string name, string account, u32 serverid, int platform, CSession* session)
	:mPid(pid)
	,mpSession(session){
	char buff[1024];
	sprintf_s(buff, 1024, "call create_player(%d, '%s', '%s', %d, %d)",
		pid,
		name.c_str(),
		account.c_str(),
		serverid,
		platform);
	mSqls.push_back(buff);
}

void CCreateRole::Run() {
	mpResult = mpStmt->executeQuery(mSqls[0].c_str());
	if (mpResult && mpResult->next()) {
		int vret = mpResult->getInt("vret");
		if (vret == 0)
			mSuccess = true;
	}
}

void CCreateRole::Finish() {
	if (mSuccess) {
		//如果创建成功了 就需要加载玩家
		gDBLoadMgr->AddTask(new CLoadPlayer(mPid, mpSession));
	}
}
//#############################################
CLoadPlayer::CLoadPlayer(u32 pid, CSession* session){
	//这里将玩家创建出来 待会儿填充数据
	mpPlayer = new CPlayer();
	mpPlayer->mId = pid;
	mpPlayer->mpSession = session;
	session->SetPlayer(mpPlayer);
	//组装sqls
	//char buff[1024];
	//sprintf_s(buff, 1024, "SELECT * FROM userbase WHERE pid = %d;", mpPlayer->mId);
	//mSqls.push_back(buff);
}

void CLoadPlayer::Run() {
	char buff[1024];
	//加载基本数据
	sprintf_s(buff, 1024, "SELECT * FROM userbase WHERE pid = %d;", mpPlayer->mId);
	mpResult = mpStmt->executeQuery(buff);
	if (mpResult && mpResult->next()) {
		mpPlayer->mName = mpResult->getString("pname").c_str();
		mpPlayer->mAccount = mpResult->getString("paccount").c_str();
		mpPlayer->mServerId = mpResult->getInt("pserverid");
		mpPlayer->mPlatform = mpResult->getInt("pplatform");
		mpPlayer->mCreateTime = mpResult->getString("timecreate").c_str();
		mpPlayer->mOfflineTime = mpResult->getString("timeoffline").c_str();
		mpPlayer->mOnlineTime = mpResult->getString("timeonline").c_str();
	}
	else {
		return;  //加载数据失败退出
	}
	mpResult->close();
	mpResult = nullptr;
	//加载玩家扩展数据
	sprintf_s(buff, 1024, "SELECT * FROM userextend WHERE pid = %d;", mpPlayer->mId);
	mpResult = mpStmt->executeQuery(buff);
	if (mpResult && mpResult->next()) {
		mpPlayer->mLevel = mpResult->getUInt("plevel");
		mpPlayer->mResId = mpResult->getUInt("presid");
		mpPlayer->mCoin = mpResult->getUInt("pcoin");
		mpPlayer->mExp = mpResult->getUInt("pexp");
	}
	else {
		return;  //加载数据失败退出
	}
	mpResult->close();
	mpResult = nullptr;
	//加载玩家充值数据
	sprintf_s(buff, 1024, "SELECT * FROM uservip WHERE pid = %d;", mpPlayer->mId);
	mpResult = mpStmt->executeQuery(buff);
	if (mpResult && mpResult->next()) {
		CVIPData* pdata = mpPlayer->GetVipData();
		pdata->mGem = mpResult->getUInt("pgem");
		pdata->mTotalGems = mpResult->getUInt("ptotalgems");
		pdata->mTotalCharge = mpResult->getUInt("ptotalcharge");
		pdata->mLastChargeTime = mpResult->getString("timelastcharge").c_str();
		//这里设置读取数据成功
		mSuccess = true;
	}
}

void CLoadPlayer::Finish() {
	if (!mSuccess) {
		if(mpPlayer)
			delete mpPlayer;
		return;
	}
	//加载完数据 需要向playermgr注册
	CPlayerMgr::GetInstance()->RegisterPlayer(mpPlayer);
}
//#############################################