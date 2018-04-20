#pragma once

class CFightServerMsg : public CSingleton<CFightServerMsg>, public IMsgHandle {
	SINGLETION_FRIEND_CLASS_REGISTER(CFightServerMsg)
private:
	CFightServerMsg();
	~CFightServerMsg() = default;
//public:
//	static void Register(s32 sessionid);
public:
	//初始化
	M_MsgHandle(NET_F2G_Init, nullptr)
	//测试用
	M_MsgHandle(NET_F2G_CreateRole, nullptr)
public:
	//将该消息对应的sessionid保存下来(发送消息时使用)
	s32 mSessionId{ 0 };
};