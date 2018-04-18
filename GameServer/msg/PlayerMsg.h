#pragma once 

class CPlayerMsg {
public:
	//注册所有需要处理的消息
	static void Register();
public:
	//登录消息
	M_MsgHandle(NET_C2S_Login, new NetLogin())
	//创建新角色
	M_MsgHandle(NET_C2S_CreateRole, new NetCreateRole())
};