#include "stdafx.h"

CFightServerMsg::CFightServerMsg() {
	//在这里注册所有玩家的消息
	M_RegisterHandle(NET_F2G_Init);
	M_RegisterHandle(NET_F2G_CreateRole);
}

//void CFightServerMsg::Register(s32 sessionid) {
//	//先保存session id
//	mSessionId = sessionid;
//	//再注册处理函数
//	auto pInstance = CProtoMgr::GetInstance();
//	M_RegisterHandle(NET_F2G_Init);
//	M_RegisterHandle(NET_F2G_CreateRole);
//}

bool CFightServerMsg::OnHandleNET_F2G_Init(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	return true;
}

bool CFightServerMsg::OnHandleNET_F2G_CreateRole(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	return true;
}