#pragma once

class CFightServerMsg : public CSingleton<CFightServerMsg>, public IMsgHandle {
	SINGLETION_FRIEND_CLASS_REGISTER(CFightServerMsg)
private:
	CFightServerMsg();
	~CFightServerMsg() = default;
//public:
//	static void Register(s32 sessionid);
public:
	//��ʼ��
	M_MsgHandle(NET_F2G_Init, nullptr)
	//������
	M_MsgHandle(NET_F2G_CreateRole, nullptr)
public:
	//������Ϣ��Ӧ��sessionid��������(������Ϣʱʹ��)
	s32 mSessionId{ 0 };
};