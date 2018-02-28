#pragma once

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