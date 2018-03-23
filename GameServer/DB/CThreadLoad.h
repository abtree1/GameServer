#pragma once

class CThreadLoad : public CSingleton<CThreadLoad>, public IDBThread {
	SINGLETION_FRIEND_CLASS_REGISTER(CThreadLoad)
public:
	CThreadLoad();
	~CThreadLoad();
public:
	void ConnectDB() override;
};

extern CThreadLoad* gDBLoadMgr;