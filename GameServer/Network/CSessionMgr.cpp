#include "stdafx.h"

CSessionMgr::CSessionMgr() {
	//��ȡnet �����
	mpMgr = NetIOCP::gGetSessionMgr();
	//�����ע��ص�ʵ��
	mpMgr->registerHandle(&mpSessionHandle);
}

CSessionMgr::~CSessionMgr() {
	//�������������session
	for (CSession* session : mpSessionVec) {
		delete session;
	}
	
	//���ٿ�ʵ��
	NetIOCP::gDestorySessionMgr();
}

void CSessionMgr::Start(string ip, int port) {
	//ע����Ϣ������
	CPlayerMsg::Register();
	//��ʼ�������
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
		//������Ϣ
		it->Recv();
	}
	std::this_thread::sleep_for(1s);
}