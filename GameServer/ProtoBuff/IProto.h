#pragma once

template<typename T, typename U>
class IProto {
public:
	typedef T* (*msg_create)();
	typedef bool(*msg_handle)(U* owner, T* pMsg);
public:
	struct SMsgHandle {
		msg_create mFunCreate;  //保存消息所带参数的结构信息，用于解析消息参数
		msg_handle mFunHandle;  //保存消息的处理函数指针
	};
public:
	//注册所有的消息和对应的处理函数
	virtual bool RegisterProto(UINT, msg_create, msg_handle) = 0;
	//获取消息对应的处理函数
	virtual SMsgHandle* GetProtoHandle(UINT) = 0;
protected:
	//这里注册所有的消息 和对应的 处理函数
	map<UINT, shared_ptr<SMsgHandle>> mMsgHandles;
};