#pragma once
//线程的状态
enum class EThreadState : u8 {
	ETS_None = 0,  //初始状态
	ETS_Run = 1,		//子线程运行
	ETS_WaitExit = 2, //子线程等待退出
	ETS_Exit = 3  //子线程退出
};

template<typename T>
class IThread {
public:
	virtual void AddTask(T* t) {  //添加任务（主线程）
		if (!t)
			return;
		std::lock_guard<std::mutex> lock(_mutex_task);
		mTasks.push(t);
	}
	virtual void Run() {	//子线程（处理任务）
		std::lock_guard<std::mutex> lock(_mutex_task);
		std::lock_guard<std::mutex> lock1(_mutex_finishtask);
		if (mTasks.empty())
			return;
		IDBTask* t = mTasks.front();
		mTasks.pop();
		if (t) {
			t->Run();
			mFinishTasks.push(t);
		}
	}
	virtual void Finish() {  //主线程 获取结果
		std::lock_guard<std::mutex> lock(_mutex_finishtask);
		if (mFinishTasks.empty())
			return;
		IDBTask* t = mFinishTasks.front();
		mFinishTasks.pop();
		if (t) {
			t->Finish();
			delete t;
		}
	}
	virtual void Close() {  //关闭线程（不再接收任务）
		if (HasTask())
			mState = EThreadState::ETS_WaitExit;
		else
			mState = EThreadState::ETS_Exit;
	}
	virtual bool HasTask() { //是否还有任务
		return !(mTasks.empty() && mFinishTasks.empty());
	}
	virtual bool IsExit() {  //是否已经退出
		return mState == EThreadState::ETS_Exit;
	}
	virtual bool IsClose() {  //线程是否已经关闭
		return mState >= EThreadState::ETS_WaitExit;
	}
protected:
	//是否退出
	EThreadState mState{ EThreadState::ETS_None };
	queue<T*> mTasks;  //等待处理的任务
	queue<T*> mFinishTasks;  //处理完成 等待完成处理的任务
	std::mutex _mutex_task; //用于线程的锁
	std::mutex _mutex_finishtask; //用于线程的锁
};

class IDBThread : public IThread<IDBTask>{
public:
	//连接上DB
	virtual void ConnectDB() = 0;
	virtual bool IsConnectDB() { return mbDBConnect; }
public:
	virtual void Run() override {
		if (!IsConnectDB())
			return;
		std::lock_guard<std::mutex> lock(_mutex_task);
		std::lock_guard<std::mutex> lock1(_mutex_finishtask);
		if (mTasks.empty())
			return;
		IDBTask* t = mTasks.front();
		mTasks.pop();
		if (!t)
			return;
		t->RunDB(mpConn, mpStmt);
		mFinishTasks.push(t);
	}
protected:
	//DB相关
	sql::mysql::MySQL_Driver* mpDriver; //数据库driver
	sql::Connection* mpConn; //数据库connection
	sql::Statement* mpStmt; //数据库的操作指针
	bool mbDBConnect{ false };  //是否连接了DB
};