#include "stdafx.h"

CSessionMgr::CSessionMgr() {
	//��ȡnet �����
	mpMgr = NetIOCP::gGetSessionMgr();
	//�����ע��ص�ʵ��
	mpMgr->registerHandle(&mpSessionHandle);
}

CSessionMgr::~CSessionMgr() {
	//�������������session
	for (auto it : mpSessionVec) {
		if (it.second)
			delete it.second;
	}
	
	//��ֹͣiocp
	mpMgr->stop();
	//���ٿ�ʵ��
	NetIOCP::gDestorySessionMgr();
}

void CSessionMgr::Start(string ip, int port) {
	//��ʼ�������
	mpMgr->start(ip, port, 0);
}

int CSessionMgr::Connect(string ip, int port) {
	auto* pSession = mpMgr->Connect(ip, port);
	if (!pSession)
		return 0;  //��ʾ����ʧ��
	if (!HandleConnect(pSession))
		return 0; //��ʾ����ʧ��
	return pSession->GetSessionId();
}

bool CSessionMgr::HandleConnect(NetIOCP::ISession* pSession) {
	CSession* session = new CSession(pSession);
	if (!session)
		return false;

	mpSessionVec[pSession->GetSessionId()] = session;
	return true;
}

CSession* CSessionMgr::FindSession(int sessionid) {
	auto it = mpSessionVec.find(sessionid);
	if (it != mpSessionVec.end())
		return it->second;
	return nullptr;
}

bool CSessionMgr::SendToSession(int sessionid, UINT type, ::google::protobuf::Message* msg) {
	CSession* pSession = FindSession(sessionid);
	if (!pSession)
		return false;
	pSession->Send(type, msg);
}

bool CSessionMgr::HandleDisconnect(NetIOCP::ISession* pSession) {
	//Ŀǰֻ�����򵥵Ĵ��� ���滹��������Ҫ����Ķ���
	mpSessionVec.erase(pSession->GetSessionId());
	return true;
}

void CSessionMgr::Update() {
	for (auto &it : mpSessionVec) {
		//������Ϣ
		if(it.second)
			it.second->Recv();
	}
	std::this_thread::sleep_for(1s);
}