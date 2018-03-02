#pragma once

#define TimerTaskFunc(type) \
static void OnHandle##type(CTimeTaskData*);

class CTimeTask {
public:
	//注册所有处理函数
	static void Register();
public:
	//测试类型
	TimerTaskFunc(ETTT_None)
};