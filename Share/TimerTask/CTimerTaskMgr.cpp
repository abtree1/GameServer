#include "stdafx.h"

CTimerTaskMgr::CTimerTaskMgr() {
	//�������а�û��rank�ֶ� �����޳�
	mTimeTaskEvent.Init(false, 0);
}

UINT CTimerTaskMgr::AddTimerTask(time_t time, ETimerTaskType type, CTimeTaskData* params) {
	//��װһ���µ�Timer Task
	STimerTaskData data;
	data.time = time;
	data.type = type;
	data.params.CopyFrom(*params);
	return AddTimerTask(data);
}

UINT CTimerTaskMgr::AddTimerTask(STimerTaskData& task) {
	task.id = CIdentity::NewId(EIdType::EID_TimerTask); //NewId();
	//���µ�Timer Task�����ȥ
	mTimeTaskEvent.DealRankList(task);
	return task.id;  //idΪ0ʱ ��ʾע��timer task ʧ��
}

bool CTimerTaskMgr::DelTimerTask(UINT id) {
	mTimeTaskEvent.DelEvent(id);
	return true;
}

void CTimerTaskMgr::Update() {
	time_t now = CTime::GetTimeStamp();
	while (STimerTaskData* evt = mTimeTaskEvent.GetBack()) {
		if (evt->time <= now) {
			//����timer task
			mTimeTaskHandle.RunTask(evt->type, &evt->params);
			//ɾ��β�� timer task
			mTimeTaskEvent.DelTail();
		}
		else {
			break;
		}
	}
}

void CTimerTaskMgr::SaveToDB(vector<string>& sqls) {
	vector<STimerTaskData>* tasks;
	mTimeTaskEvent.SaveToDB(tasks);
	for (STimerTaskData &data : tasks) {

	}
}

void CTimerTaskMgr::LoadFromDB() {

}