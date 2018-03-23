#pragma once

#define MsgHandle(msg,msgdata) \
	static ::google::protobuf::Message* OnCreate##msg() { return msgdata; } \
	static bool OnHandle##msg(CSession* owner, ::google::protobuf::Message* pBaseMsg); 

class CPlayerMsg {
public:
	//ע��������Ҫ�������Ϣ
	static void Register();
public:
	//��¼��Ϣ
	MsgHandle(NET_C2S_Login, new NetLogin())
	//�����½�ɫ
	MsgHandle(NET_C2S_CreateRole, new NetCreateRole())
};