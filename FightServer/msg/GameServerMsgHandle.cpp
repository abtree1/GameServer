#include "stdafx.h"

CGameServerMsgHandle::CGameServerMsgHandle() {
	//������ע��������ҵ���Ϣ
	M_RegisterHandle(NET_G2F_Init);
	M_RegisterHandle(NET_G2F_CreateRole);
}

bool CGameServerMsgHandle::OnHandleNET_G2F_Init(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	//�ط���ʼ����Ϣ
	owner->Send(NET_F2G_Init, nullptr);
	return true;
}

bool CGameServerMsgHandle::OnHandleNET_G2F_CreateRole(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	return true;
}