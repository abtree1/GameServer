#include "stdafx.h"

CSessionMgr::CSessionMgr() {
	//获取net 库对象
	mpMgr = NetIOCP::gGetSessionMgr();
	//向对象注册回调实例
	mpMgr->registerHandle(&mpSessionHandle);
}

CSessionMgr::~CSessionMgr() {
	//销毁所有连入的session
	for (CSession* session : mpSessionVec) {
		delete session;
	}
	
	//销毁库实例
	NetIOCP::gDestorySessionMgr();
}

void CSessionMgr::Start(string ip, int port) {
	//注册消息处理函数
	CPlayerMsg::Register();
	//开始网络监听
	mpMgr->start(ip, port, 0);
}

bool CSessionMgr::HandleConnect(NetIOCP::ISession* pSession) {
	CSession* session = new CSession(pSession);
	if (!session)
		return false;

	mpSessionVec.push_back(session);
	return true;
}

void CSessionMgr::Update() {
	for (auto &it : mpSessionVec) {
		//接收消息
		it->Recv();
	}
	std::this_thread::sleep_for(1s);
}