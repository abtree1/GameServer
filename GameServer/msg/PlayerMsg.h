#pragma once 

class CPlayerMsg : public CSingleton<CPlayerMsg>, public IMsgHandle {
	SINGLETION_FRIEND_CLASS_REGISTER(CPlayerMsg)
private:
	CPlayerMsg();
	~CPlayerMsg() = default;
//public:
	//ע��������Ҫ�������Ϣ
	//void Register();
public:
	//��¼��Ϣ
	M_MsgHandle(NET_C2S_Login, new NetLogin())
	//�����½�ɫ
	M_MsgHandle(NET_C2S_CreateRole, new NetCreateRole())
};