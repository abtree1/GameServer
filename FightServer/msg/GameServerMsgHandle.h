#pragma once

class CGameServerMsgHandle {
public:
	//ע��������Ҫ�������Ϣ
	static void Register();
public:
	//��ʼ����Ϣ
	M_MsgHandle(NET_G2F_Init, nullptr)
	//����ʱʹ��
	M_MsgHandle(NET_G2F_CreateRole, nullptr)
};