#include "stdafx.h"

//在这里注册所有玩家的消息
void CPlayerMsg::Register() {
	auto pInstance = CProtoMgr::GetInstance();
	M_RegisterHandle(NET_C2S_Login);
	M_RegisterHandle(NET_C2S_CreateRole);
	//pInstance->RegisterProto(NET_C2S_Login, OnCreateNET_C2S_Login, OnHandleNET_C2S_Login);
}

bool CPlayerMsg::OnHandleNET_C2S_Login(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	NetLogin* pMsg = dynamic_cast<NetLogin*>(pBaseMsg);
#ifdef _DEBUG
	cout << pMsg->account().c_str() << " quest login" << endl;
#endif // _DEBUG
	//第一步 检查是否已经在内存中了
	string account = pMsg->account();
	CPlayer* pPlayer = CPlayerMgr::GetInstance()->GetPlayerByAccount(account);
	if (pPlayer != nullptr) {
		//处理内存玩家上线流程
		pPlayer->mpSession = owner;
		owner->SetPlayer(pPlayer);
		return true;
	}
	//玩家不再内存中 在数据库查找
	CSPNextData nkey;
	nkey.set_type(ENDKT_LoginPrepare);
	nkey.set_ivalue(owner->GetSessionId());
	CNextData* npdata = CNextDataMgr::GetInstance()->findTemp(nkey);
	if (npdata != nullptr) {
		//说明已经注册完成的 不需要重复注册
		return true;
	}
	//创建一个临时存数据的空间
	npdata = CNextDataMgr::GetInstance()->createTemp(nkey);
	if (!npdata)  //如果分配失败 说明服务器发生错误 此时不让登录
		return false;
	//存入数据 在角色创建完成后交由角色使用
	npdata->AddData<INT>(pMsg->serverid());
	npdata->AddData<INT>(pMsg->platform());
	npdata->AddData<string>(pMsg->token());
	npdata->AddData<string>(account);
	//数据库操作
	gDBLoadMgr->AddTask(new CPrepareLogin(account, pMsg->serverid(), owner));
	return true;
}

bool CPlayerMsg::OnHandleNET_C2S_CreateRole(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	NetCreateRole* pMsg = dynamic_cast<NetCreateRole*>(pBaseMsg);
	//读出提前保存的玩家数据
	CSPNextData key;
	key.set_type(ENDKT_LoginPrepare);
	key.set_ivalue(owner->GetSessionId());
	CNextData* npdata = CNextDataMgr::GetInstance()->findTemp(key);
	if (!npdata) {
		//如果next data 丢失了 此次创建新角色失败
		return false;
	}
	//注册创建角色事件
	gDBSaveMgr->AddTask(new CCreateRole(
		gIdentify->NewId(EID_PlayerId)  //pid
		, pMsg->name().c_str()			//name
		, npdata->GetData<string>(3).c_str()  //account
		, npdata->GetData<INT>(0)		//serverid
		, npdata->GetData<INT>(1)		//platform
		, owner));	
	//处理完成后执行清除操作
	CNextDataMgr::GetInstance()->dirtyHandleTemp(key);
	return true;
}