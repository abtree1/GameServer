#include "stdafx.h"

void thread_func(CThreadSave* pMgr) {
	pMgr->ConnectDB();
	//�����û�˳�
	if (!pMgr->IsClose() || pMgr->HasTask()) {
		pMgr->Run();
	}
}

CThreadSave::CThreadSave() {
	//�����߳�
	std::thread th1(thread_func, this);
	th1.detach();
	//�Ѿ���ʼ�����߳�
	mState == EThreadState::ETS_Run;
}

CThreadSave::~CThreadSave() {
	//������Դ
	if (mpStmt)
		delete mpStmt;
	if (mpConn)
		delete mpConn;
	if (mpDriver)
		delete mpDriver;
}

void CThreadSave::ConnectDB() {
	try {
		//���̰߳�ȫ ��ȡdriver
		mpDriver = sql::mysql::get_mysql_driver_instance();
		mpConn = mpDriver->connect("tcp://127.0.0.1:3306?useServerPrepStmts=true&cachePrepStmts=true", "root", "root");
		mpStmt = mpConn->createStatement();
		//�������ݿ�
		mpStmt->execute("CREATE DATABASE IF NOT EXISTS cpptest DEFAULT CHARSET utf8 COLLATE utf8_general_ci;");
		mpStmt->execute("use cpptest;");
		//�鿴����Ϣ
		sql::ResultSet* res = mpStmt->executeQuery("SELECT COUNT(*) as ex FROM information_schema.`TABLES` WHERE TABLE_NAME = 'alter_log' and TABLE_SCHEMA = 'cpptest';");
		bool isExist = false;
		if (res->next()) {
			if (res->getUInt("ex") == 1) {
				isExist = true;
			}
		}
		//������������ݿ�������¼ �򴴽�
		if (!isExist) {
			mpStmt->execute("CREATE TABLE alter_log(id INT)");
		}
		
		mbDBConnect = true;
	}
	catch(const std::exception& e){
		printf(e.what());
	}
}

void CThreadSave::AddTask(shared_ptr<IDBTask>& t) {

}

void CThreadSave::Run() {

}

void CThreadSave::Finish() {

}