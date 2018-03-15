#pragma once
/************************************************************************
	Timer Task 为有序不定长数组(已触发时间先后为序)
	其中尾部（高位）为最先触发的Timer Task，头部为最后触发Task
 ************************************************************************/
class CTimerTaskMgr : public CSingleton<CTimerTaskMgr>{
	SINGLETION_FRIEND_CLASS_REGISTER(CTimerTaskMgr)
private:
	CTimerTaskMgr();
public:
	//添加Timer Task
	UINT AddTimerTask(time_t time, ETimerTaskType type, CTimeTaskData* params);
	UINT AddTimerTask(STimerTaskData& task);
	//取消Timer Task
	bool DelTimerTask(UINT id);
	//更新
	void Update();
public:
	//数据库操作
	void SaveToDB();
	void LoadFromDB();
//private:
	//获得一个新的task id
	//UINT NewId() { return ++mMaxId; }
public:
	//获取操作函数的句柄
	CTimerTaskHandle* GetTimerTaskHandle() { return &mTimeTaskHandle; }
private:
	//保存timer task 的操作函数
	CTimerTaskHandle mTimeTaskHandle;
	//保存所有注册的 TimerTask
	CTimerTaskEvent mTimeTaskEvent;
	//维护类型与id映射
	multimap<ETimerTaskType, UINT> mTaskTypeToIds;
	//id策略(当前使用的最大I的)
	//UINT mMaxId{ 0 };
};