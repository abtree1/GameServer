#pragma once 

class CPlayerMsg {
public:
	//ע��������Ҫ�������Ϣ
	static void Register();
public:
	//��¼��Ϣ
	M_MsgHandle(NET_C2S_Login, new NetLogin())
	//�����½�ɫ
	M_MsgHandle(NET_C2S_CreateRole, new NetCreateRole())
};