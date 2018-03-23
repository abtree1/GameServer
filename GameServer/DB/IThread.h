#pragma once
//�̵߳�״̬
enum class EThreadState : u8 {
	ETS_None = 0,  //��ʼ״̬
	ETS_Run = 1,		//���߳�����
	ETS_WaitExit = 2, //���̵߳ȴ��˳�
	ETS_Exit = 3  //���߳��˳�
};

template<typename T>
class IThread {
public:
	virtual void AddTask(T* t) {  //����������̣߳�
		if (!t)
			return;
		std::lock_guard<std::mutex> lock(_mutex_task);
		mTasks.push(t);
	}
	virtual void Run() {	//���̣߳���������
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
	virtual void Finish() {  //���߳� ��ȡ���
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
	virtual void Close() {  //�ر��̣߳����ٽ�������
		if (HasTask())
			mState = EThreadState::ETS_WaitExit;
		else
			mState = EThreadState::ETS_Exit;
	}
	virtual bool HasTask() { //�Ƿ�������
		return !(mTasks.empty() && mFinishTasks.empty());
	}
	virtual bool IsExit() {  //�Ƿ��Ѿ��˳�
		return mState == EThreadState::ETS_Exit;
	}
	virtual bool IsClose() {  //�߳��Ƿ��Ѿ��ر�
		return mState >= EThreadState::ETS_WaitExit;
	}
protected:
	//�Ƿ��˳�
	EThreadState mState{ EThreadState::ETS_None };
	queue<T*> mTasks;  //�ȴ����������
	queue<T*> mFinishTasks;  //������� �ȴ���ɴ��������
	std::mutex _mutex_task; //�����̵߳���
	std::mutex _mutex_finishtask; //�����̵߳���
};

class IDBThread : public IThread<IDBTask>{
public:
	//������DB
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
	//DB���
	sql::mysql::MySQL_Driver* mpDriver; //���ݿ�driver
	sql::Connection* mpConn; //���ݿ�connection
	sql::Statement* mpStmt; //���ݿ�Ĳ���ָ��
	bool mbDBConnect{ false };  //�Ƿ�������DB
};