#pragma once

//template<typename T, typename U>
class IProto {
public:
	//ע�����е���Ϣ�Ͷ�Ӧ�Ĵ�����
	virtual bool RegisterHandle(s32, IMsgHandle*) = 0;
	//ע��Ĭ����Ϣ������
	virtual bool RegisterDefHandle(IMsgHandle*) = 0;
	//��ȡ��Ϣ��Ӧ�Ĵ�����
	virtual IMsgHandle* GetProtoHandle(s32) = 0;
protected:
	map<s32, IMsgHandle*> mRegisterMsgHandles;
	IMsgHandle* mDefaultMsgHandle;
	//����ע�����е���Ϣ �Ͷ�Ӧ�� ������
	//map<UINT, shared_ptr<SMsgHandle>> mMsgHandles;
};