#pragma once

enum ETimerTaskType {
	ETTT_None = 0,  //������
};

//��������timer task ��Ӧ�Ĵ�����
class CTimerTaskHandle {
public:
	using Func = void(*)(CTimeTaskData*);
public:
	//ע�����е����ͺͶ�Ӧ�Ĵ�����
	bool RegisterHandle(ETimerTaskType type, Func func);
	//����timer task
	bool RunTask(ETimerTaskType type, CTimeTaskData* params);
private:
	//��������ע���timer task ��Ϣ�ʹ�����
	map<ETimerTaskType, Func> mMsgHandles;
};