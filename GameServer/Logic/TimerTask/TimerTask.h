#pragma once

#define TimerTaskFunc(type) \
static void OnHandle##type(CTimeTaskData*);

class CTimeTask {
public:
	//ע�����д�����
	static void Register();
public:
	//��������
	TimerTaskFunc(ETTT_None)
};