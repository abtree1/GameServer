#include "stdafx.h"
//#############################################
CLoadIds::CLoadIds() {
	char buff[1024];
	sprintf_s(buff, 1024, "SELECT pid FROM userbase WHERE pserverid = %d ORDER BY pid DESC LIMIT 1",
		gConfigMgr->GetSettingValue<INT>(SERVERID));
	mSqls.push_back(buff);
}

void CLoadIds::Run() {
	//�ȰѶ���ȡ����
	CIdentityImpl* ids = dynamic_cast<CIdentityImpl*>(gIdentify);
	map<string, u32>& idmap = ids->GetAllIds();
	//��ȡplayerid
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
	//���ü������
	gIdentify->LoadFinish();
}
//#############################################
CSaveTimerTask::CSaveTimerTask() {
	//��ȡ�洢��sqls
	CTimerTaskMgr::GetInstance()->SaveToDB(mSqls);
}

void CSaveTimerTask::Run() {

}

void CSaveTimerTask::Finish() {

}
//#############################################

CLoadTimerTask::CLoadTimerTask() {
	//��ѯ���м�¼
	mSqls.push_back("SELECT * FROM `g_timertask`");
}

void CLoadTimerTask::Run() {
	mpResult = mpStmt->executeQuery(mSqls[0]);
	while (mpResult && mpResult->next()) {
		//����ÿһ��timertask
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
	//����Ѿ������ ִ����Ҽ��ز���
	if (mHasPlayer) {
		gDBLoadMgr->AddTask(new CLoadPlayer(mPlayerId, mpSession));
		return;
	}
	//�����û����� ִ����Ҵ�������
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
		//��������ɹ��� ����Ҫ�������
		gDBLoadMgr->AddTask(new CLoadPlayer(mPid, mpSession));
	}
}
//#############################################
CLoadPlayer::CLoadPlayer(u32 pid, CSession* session){
	//���ｫ��Ҵ������� ������������
	mpPlayer = new CPlayer();
	mpPlayer->mId = pid;
	mpPlayer->mpSession = session;
	session->SetPlayer(mpPlayer);
	//��װsqls
	//char buff[1024];
	//sprintf_s(buff, 1024, "SELECT * FROM userbase WHERE pid = %d;", mpPlayer->mId);
	//mSqls.push_back(buff);
}

void CLoadPlayer::Run() {
	char buff[1024];
	//���ػ�������
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
		return;  //��������ʧ���˳�
	}
	mpResult->close();
	mpResult = nullptr;
	//���������չ����
	sprintf_s(buff, 1024, "SELECT * FROM userextend WHERE pid = %d;", mpPlayer->mId);
	mpResult = mpStmt->executeQuery(buff);
	if (mpResult && mpResult->next()) {
		mpPlayer->mLevel = mpResult->getUInt("plevel");
		mpPlayer->mResId = mpResult->getUInt("presid");
		mpPlayer->mCoin = mpResult->getUInt("pcoin");
		mpPlayer->mExp = mpResult->getUInt("pexp");
	}
	else {
		return;  //��������ʧ���˳�
	}
	mpResult->close();
	mpResult = nullptr;
	//������ҳ�ֵ����
	sprintf_s(buff, 1024, "SELECT * FROM uservip WHERE pid = %d;", mpPlayer->mId);
	mpResult = mpStmt->executeQuery(buff);
	if (mpResult && mpResult->next()) {
		CVIPData* pdata = mpPlayer->GetVipData();
		pdata->mGem = mpResult->getUInt("pgem");
		pdata->mTotalGems = mpResult->getUInt("ptotalgems");
		pdata->mTotalCharge = mpResult->getUInt("ptotalcharge");
		pdata->mLastChargeTime = mpResult->getString("timelastcharge").c_str();
		//�������ö�ȡ���ݳɹ�
		mSuccess = true;
	}
}

void CLoadPlayer::Finish() {
	if (!mSuccess) {
		if(mpPlayer)
			delete mpPlayer;
		return;
	}
	//���������� ��Ҫ��playermgrע��
	CPlayerMgr::GetInstance()->RegisterPlayer(mpPlayer);
}
//#############################################