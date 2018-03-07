#pragma once

class ITask {
public:
	virtual void Run() = 0;
	virtual void Finish() = 0;
};

class IDBTask : public ITask {
public:
	//Ϊ���߳�Run��ʼ��ֵ
	virtual void RunDB(sql::Connection* pConn, sql::Statement* pStmt) {
		mpConn = pConn;
		mpStmt = pStmt;
		Run();  //���߳��е���Run
	}
protected:
	sql::Connection* mpConn;  //���ݿ�����Ӿ��
	sql::Statement* mpStmt;	 //���ݿ�Ĳ������
	sql::ResultSet* mpResult;  //���ղ������
	vector<string> mSqls; //��Ҫ�����sql
};