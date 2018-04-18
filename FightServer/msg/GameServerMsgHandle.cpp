#include "stdafx.h"

#define RegisterHandle(msg) \
pInstance->RegisterProto(msg, OnCreate##msg, OnHandle##msg);

void CGameServerMsgHandle::Register() {
	auto pInstance = CProtoMgr::GetInstance();
	RegisterHandle(NET_G2F_Init);
	RegisterHandle(NET_G2F_CreateRole);
}

bool CGameServerMsgHandle::OnHandleNET_G2F_Init(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	//回发初始化消息
	owner->Send(NET_F2G_Init, nullptr);
	return true;
}

bool CGameServerMsgHandle::OnHandleNET_G2F_CreateRole(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	return true;
}