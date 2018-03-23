#pragma once

class CThreadSave : public CSingleton<CThreadSave>, public IDBThread {
	SINGLETION_FRIEND_CLASS_REGISTER(CThreadSave)
private:
	CThreadSave();
	~CThreadSave();
public:
	void ConnectDB() override;
private:
	bool CheckDBInit();
	bool StructDB();
};
 
extern CThreadSave* gDBSaveMgr;