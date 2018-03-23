#pragma once

class ITask {
public:
	virtual void Run() = 0;
	virtual void Finish() = 0;
};

class IDBTask : public ITask {
public:
	//为子线程Run初始化值
	virtual void RunDB(sql::Connection* pConn, sql::Statement* pStmt) {
		mpConn = pConn;
		mpStmt = pStmt;
		Run();  //子线程中调用Run
	}
protected:
	sql::Connection* mpConn{ nullptr };  //数据库的连接句柄
	sql::Statement* mpStmt{ nullptr };	 //数据库的操作句柄
	sql::ResultSet* mpResult{ nullptr };  //接收操作结果
	vector<string> mSqls; //需要处理的sql
};