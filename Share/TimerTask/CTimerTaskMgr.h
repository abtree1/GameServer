#pragma once
/************************************************************************
	Timer Task Ϊ���򲻶�������(�Ѵ���ʱ���Ⱥ�Ϊ��)
	����β������λ��Ϊ���ȴ�����Timer Task��ͷ��Ϊ��󴥷�Task
 ************************************************************************/
class CTimerTaskMgr : public CSingleton<CTimerTaskMgr>{
	SINGLETION_FRIEND_CLASS_REGISTER(CTimerTaskMgr)
private:
	CTimerTaskMgr();
public:
	//���Timer Task
	UINT AddTimerTask(time_t time, ETimerTaskType type, CTimeTaskData* params);
	UINT AddTimerTask(STimerTaskData& task);
	//ȡ��Timer Task
	bool DelTimerTask(UINT id);
	//����
	void Update();
public:
	//���ݿ����
	void SaveToDB();
	void LoadFromDB();
//private:
	//���һ���µ�task id
	//UINT NewId() { return ++mMaxId; }
public:
	//��ȡ���������ľ��
	CTimerTaskHandle* GetTimerTaskHandle() { return &mTimeTaskHandle; }
private:
	//����timer task �Ĳ�������
	CTimerTaskHandle mTimeTaskHandle;
	//��������ע��� TimerTask
	CTimerTaskEvent mTimeTaskEvent;
	//ά��������idӳ��
	multimap<ETimerTaskType, UINT> mTaskTypeToIds;
	//id����(��ǰʹ�õ����I��)
	//UINT mMaxId{ 0 };
};