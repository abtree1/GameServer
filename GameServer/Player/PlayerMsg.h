#pragma once

#define MsgHandle(msg,msgdata) \
	static ::google::protobuf::Message* OnCreate##msg() { return msgdata; } \
	static bool OnHandle##msg(CSession* owner, ::google::protobuf::Message* pBaseMsg); 

class CPlayerMsg {
public:
	//注册所有需要处理的消息
	static void Register();
public:
	//登录消息
	MsgHandle(NET_C2S_Login, new NetLogin())
	//创建新角色
	MsgHandle(NET_C2S_CreateRole, new NetCreateRole())
};