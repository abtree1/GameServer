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
		msg_create mFunCreate;  //������Ϣ���������Ľṹ��Ϣ�����ڽ�����Ϣ����
		msg_handle mFunHandle;  //������Ϣ�Ĵ�����ָ��
	};
public:
	//ע�����е���Ϣ�Ͷ�Ӧ�Ĵ�����
	virtual bool RegisterProto(UINT type, msg_create create, msg_handle handle) {
		shared_ptr<SMsgHandle> hand = make_shared<SMsgHandle>();
		hand->mFunCreate = create;
		hand->mFunHandle = handle;
		mMsgHandles[type] = hand;
		return true;
	}
	//��ȡ��Ϣ��Ӧ�Ĵ�����
	virtual SMsgHandle* GetProtoHandle(UINT type) {
		auto it = mMsgHandles.find(type);
		if (it != mMsgHandles.end()) {
			if (it->second)
				return it->second.get();
		}
		return nullptr;
	}
protected:
	//����ע�����е���Ϣ �Ͷ�Ӧ�� ������
	map<UINT, shared_ptr<SMsgHandle>> mMsgHandles;
};
class CSession;
using IMsgHandle = IMsgHandleBase<::google::protobuf::Message, CSession>;