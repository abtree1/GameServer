#pragma once

//�洢timertask
class CSaveTimerTask : public IDBTask {
public:
	CSaveTimerTask();
public:
	void Run() override;
	void Finish() override;
};
//����timertask
class CLoadTimerTask : public IDBTask {
public:
	CLoadTimerTask();
public:
	void Run() override;
	void Finish() override;
};
