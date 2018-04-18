#pragma once
#define M_MsgHandle(msg,msgdata) \
	static ::google::protobuf::Message* OnCreate##msg() { return msgdata; } \
	static bool OnHandle##msg(CSession* owner, ::google::protobuf::Message* pBaseMsg); 

#define M_RegisterHandle(msg) \
pInstance->RegisterProto(msg, OnCreate##msg, OnHandle##msg);

template<typename T, typename U>
class IProto {
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
	virtual bool RegisterProto(UINT, msg_create, msg_handle) = 0;
	//��ȡ��Ϣ��Ӧ�Ĵ�����
	virtual SMsgHandle* GetProtoHandle(UINT) = 0;
protected:
	//����ע�����е���Ϣ �Ͷ�Ӧ�� ������
	map<UINT, shared_ptr<SMsgHandle>> mMsgHandles;
};