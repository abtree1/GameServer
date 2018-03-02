#pragma once
//用于Timer Task 的排行榜
struct STimerTaskData : public IRankListBase<STimerTaskData, UINT> {
	UINT id{ 0 };    //唯一标识任务
	UINT time{ 0 };	//任务触发时间
	ETimerTaskType type{ ETTT_None };  //timer task 的类型
	CTimeTaskData params;  //任务数据

	STimerTaskData &operator=(const STimerTaskData&) override;
	UINT GetId() override;
};
//timer task 采用时时刷新机制
class CTimerTaskEvent : public IRankListSync<STimerTaskData> {
public:
	void DelEvent(int pos);  //删除指定位置的项
	void DelTail(); //删除尾上的项（最先触发）
	STimerTaskData* GetBack(); 
};