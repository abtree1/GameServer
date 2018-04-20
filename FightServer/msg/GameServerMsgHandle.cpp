#include "stdafx.h"

CGameServerMsgHandle::CGameServerMsgHandle() {
	//在这里注册所有玩家的消息
	M_RegisterHandle(NET_G2F_Init);
	M_RegisterHandle(NET_G2F_CreateRole);
}

bool CGameServerMsgHandle::OnHandleNET_G2F_Init(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	//回发初始化消息
	owner->Send(NET_F2G_Init, nullptr);
	return true;
}

bool CGameServerMsgHandle::OnHandleNET_G2F_CreateRole(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	return true;
}