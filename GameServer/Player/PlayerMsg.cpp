#include "stdafx.h"

#define RegisterHandle(msg) \
pInstance->RegisterProto(msg, OnCreate##msg, OnHandle##msg);

void CPlayerMsg::Register() {
	auto pInstance = CProtoMgr::GetInstance();
	RegisterHandle(NET_C2S_Login);
	//pInstance->RegisterProto(NET_C2S_Login, OnCreateNET_C2S_Login, OnHandleNET_C2S_Login);
}

bool CPlayerMsg::OnHandleNET_C2S_Login(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	NetLogin* pMsg = dynamic_cast<NetLogin*>(pBaseMsg);
	cout << pMsg->name() << " " << pMsg->account() << " " << pMsg->password() << endl;
	owner->Send(NET_C2S_Login, pMsg);
	return true;
}