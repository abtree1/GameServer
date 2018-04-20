#pragma once

//template<typename T, typename U>
class IProto {
public:
	//注册所有的消息和对应的处理函数
	virtual bool RegisterHandle(s32, IMsgHandle*) = 0;
	//注册默认消息操作类
	virtual bool RegisterDefHandle(IMsgHandle*) = 0;
	//获取消息对应的处理函数
	virtual IMsgHandle* GetProtoHandle(s32) = 0;
protected:
	map<s32, IMsgHandle*> mRegisterMsgHandles;
	IMsgHandle* mDefaultMsgHandle;
	//这里注册所有的消息 和对应的 处理函数
	//map<UINT, shared_ptr<SMsgHandle>> mMsgHandles;
};