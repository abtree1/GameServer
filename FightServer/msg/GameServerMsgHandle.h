#pragma once

class CGameServerMsgHandle : public CSingleton<CGameServerMsgHandle>, public IMsgHandle {
	SINGLETION_FRIEND_CLASS_REGISTER(CGameServerMsgHandle)
private:
	CGameServerMsgHandle();
	~CGameServerMsgHandle() = default;
//public:
//	//ע��������Ҫ�������Ϣ
//	static void Register();
public:
	//��ʼ����Ϣ
	M_MsgHandle(NET_G2F_Init, nullptr)
	//����ʱʹ��
	M_MsgHandle(NET_G2F_CreateRole, nullptr)
};