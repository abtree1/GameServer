#pragma once

class CThreadSave : public CSingleton<CThreadSave>, public IDBThread {
	SINGLETION_FRIEND_CLASS_REGISTER(CThreadSave)
private:
	CThreadSave();
	~CThreadSave();
public:
	void ConnectDB() override;
public:
	void AddTask(shared_ptr<IDBTask>& t) override;
	void Run() override;
	void Finish() override;
};