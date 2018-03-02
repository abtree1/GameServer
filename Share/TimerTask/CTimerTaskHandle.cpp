#include "stdafx.h"

bool CTimerTaskHandle::RegisterHandle(ETimerTaskType type, Func func) {
	mMsgHandles[type] = func;
	return true;
}

bool CTimerTaskHandle::RunTask(ETimerTaskType type, CTimeTaskData* params) {
	auto it = mMsgHandles.find(type);
	if (it != mMsgHandles.end()) {
		if (it->second) {
			(*it->second)(params);
		}
	}
	return false;
}