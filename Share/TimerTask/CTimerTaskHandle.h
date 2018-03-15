#pragma once

//枚举定义不写在公共库里面 
//而应该定义在没有项目里面 作为项目的私有数据
//enum ETimerTaskType {
//	ETTT_None = 0,  //测试用
//};

//保存所有timer task 对应的处理函数
class CTimerTaskHandle {
public:
	using Func = void(*)(CTimeTaskData*);
public:
	//注册所有的类型和对应的处理函数
	bool RegisterHandle(ETimerTaskType type, Func func);
	//触发timer task
	bool RunTask(ETimerTaskType type, CTimeTaskData* params);
private:
	//保存所有注册的timer task 消息和处理函数
	map<ETimerTaskType, Func> mMsgHandles;
};