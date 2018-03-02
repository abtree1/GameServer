#include "stdafx.h"

CTimerTaskMgr::CTimerTaskMgr() {
	//设置排行榜没有rank字段 且无限长
	mTimeTaskEvent.Init(false, 0);
}

UINT CTimerTaskMgr::AddTimerTask(time_t time, ETimerTaskType type, CTimeTaskData* params) {
	//组装一个新的Timer Task
	STimerTaskData data;
	data.time = time;
	data.type = type;
	data.params.CopyFrom(*params);
	return AddTimerTask(data);
}

UINT CTimerTaskMgr::AddTimerTask(STimerTaskData& task) {
	task.id = NewId();
	//将新的Timer Task加入进去
	mTimeTaskEvent.DealRankList(task);
	return task.id;  //id为0时 表示注册timer task 失败
}

bool CTimerTaskMgr::DelTimerTask(UINT id) {
	mTimeTaskEvent.DelEvent(id);
	return true;
}

void CTimerTaskMgr::Update() {
	time_t now = CTime::GetTimeStamp();
	while (STimerTaskData* evt = mTimeTaskEvent.GetBack()) {
		if (evt->time <= now) {
			//触发timer task
			mTimeTaskHandle.RunTask(evt->type, &evt->params);
			//删除尾部 timer task
			mTimeTaskEvent.DelTail();
		}
		else {
			break;
		}
	}
}

void CTimerTaskMgr::SaveToDB() {

}

void CTimerTaskMgr::LoadFromDB() {

}