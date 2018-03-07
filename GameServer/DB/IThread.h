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
	virtual void AddTask(shared_ptr<T>& t) = 0;  //����������̣߳�
	virtual void Run() = 0;	//���̣߳���������
	virtual void Finish() = 0;  //���߳� ��ȡ���
	virtual void Close() {  //�ر��̣߳����ٽ�������
		if (HasTask())
			mState = EThreadState::ETS_WaitExit;
		else
			mState = EThreadState::ETS_Exit;
	}
	virtual bool HasTask() { //�Ƿ�������
		return !mTasks.empty();
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
	vector<shared_ptr<T>> mTasks;  //�ȴ����������
	//vector<shared_ptr<T>> mWaitFinishTasks;  //�ȴ���ɴ��������
	std::mutex __mutex__; //�����̵߳���
};

class IDBThread : public IThread<IDBTask>{
public:
	//������DB
	virtual void ConnectDB() = 0;
	virtual bool IsConnectDB() { return mbDBConnect; }
protected:
	//DB���
	sql::mysql::MySQL_Driver* mpDriver; //���ݿ�driver
	sql::Connection* mpConn; //���ݿ�connection
	sql::Statement* mpStmt; //���ݿ�Ĳ���ָ��
	bool mbDBConnect{ false };  //�Ƿ�������DB
};