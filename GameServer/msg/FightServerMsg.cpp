#include "stdafx.h"

CFightServerMsg::CFightServerMsg() {
	//������ע��������ҵ���Ϣ
	M_RegisterHandle(NET_F2G_Init);
	M_RegisterHandle(NET_F2G_CreateRole);
}

//void CFightServerMsg::Register(s32 sessionid) {
//	//�ȱ���session id
//	mSessionId = sessionid;
//	//��ע�ᴦ����
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