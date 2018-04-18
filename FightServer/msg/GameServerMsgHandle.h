#pragma once

class CGameServerMsgHandle {
public:
	//注册所有需要处理的消息
	static void Register();
public:
	//初始化消息
	M_MsgHandle(NET_G2F_Init, nullptr)
	//测试时使用
	M_MsgHandle(NET_G2F_CreateRole, nullptr)
};