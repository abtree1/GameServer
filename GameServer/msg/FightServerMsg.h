#pragma once

class CFightServerMsg {
public:
	static void Register();
public:
	//��ʼ��
	M_MsgHandle(NET_F2G_Init, nullptr)
	//������
	M_MsgHandle(NET_F2G_CreateRole, nullptr)
};