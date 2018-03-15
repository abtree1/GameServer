#pragma once

//¥Ê¥¢timertask
class CSaveTimerTask : public IDBTask {
public:
	CSaveTimerTask();
public:
	void Run() override;
	void Finish() override;
};
//º”‘ÿtimertask
class CLoadTimerTask : public IDBTask {
public:
	CLoadTimerTask();
public:
	void Run() override;
	void Finish() override;
};
