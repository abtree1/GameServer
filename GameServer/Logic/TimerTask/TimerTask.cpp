#include "stdafx.h"

#define RegisterFunc(type) \
pInstance->RegisterHandle(type, OnHandle##type)

void CTimeTask::Register() {
	auto pInstance = CTimerTaskMgr::GetInstance()->GetTimerTaskHandle();
	RegisterFunc(ETTT_None);
}

void CTimeTask::OnHandleETTT_None(CTimeTaskData* params) {

}