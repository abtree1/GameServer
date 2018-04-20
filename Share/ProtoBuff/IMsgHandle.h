#pragma once

#define M_MsgHandle(msg,msgdata) \
	static ::google::protobuf::Message* OnCreate##msg() { return msgdata; } \
	static bool OnHandle##msg(CSession* owner, ::google::protobuf::Message* pBaseMsg); 

#define M_RegisterHandle(msg) \
RegisterProto(msg, OnCreate##msg, OnHandle##msg);

template<typename T, typename U>
class IMsgHandleBase {
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
	virtual bool RegisterProto(UINT type, msg_create create, msg_handle handle) {
		shared_ptr<SMsgHandle> hand = make_shared<SMsgHandle>();
		hand->mFunCreate = create;
		hand->mFunHandle = handle;
		mMsgHandles[type] = hand;
		return true;
	}
	//获取消息对应的处理函数
	virtual SMsgHandle* GetProtoHandle(UINT type) {
		auto it = mMsgHandles.find(type);
		if (it != mMsgHandles.end()) {
			if (it->second)
				return it->second.get();
		}
		return nullptr;
	}
protected:
	//这里注册所有的消息 和对应的 处理函数
	map<UINT, shared_ptr<SMsgHandle>> mMsgHandles;
};
class CSession;
using IMsgHandle = IMsgHandleBase<::google::protobuf::Message, CSession>;