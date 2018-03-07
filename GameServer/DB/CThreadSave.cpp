#include "stdafx.h"

void thread_func(CThreadSave* pMgr) {
	pMgr->ConnectDB();
	//如果还没退出
	if (!pMgr->IsClose() || pMgr->HasTask()) {
		pMgr->Run();
	}
}

CThreadSave::CThreadSave() {
	//开启线程
	std::thread th1(thread_func, this);
	th1.detach();
	//已经开始了子线程
	mState == EThreadState::ETS_Run;
}

CThreadSave::~CThreadSave() {
	//清理资源
	if (mpStmt)
		delete mpStmt;
	if (mpConn)
		delete mpConn;
	if (mpDriver)
		delete mpDriver;
}

void CThreadSave::ConnectDB() {
	try {
		//非线程安全 获取driver
		mpDriver = sql::mysql::get_mysql_driver_instance();
		mpConn = mpDriver->connect("tcp://127.0.0.1:3306?useServerPrepStmts=true&cachePrepStmts=true", "root", "root");
		mpStmt = mpConn->createStatement();
		//连接数据库
		mpStmt->execute("CREATE DATABASE IF NOT EXISTS cpptest DEFAULT CHARSET utf8 COLLATE utf8_general_ci;");
		mpStmt->execute("use cpptest;");
		//查看表信息
		sql::ResultSet* res = mpStmt->executeQuery("SELECT COUNT(*) as ex FROM information_schema.`TABLES` WHERE TABLE_NAME = 'alter_log' and TABLE_SCHEMA = 'cpptest';");
		bool isExist = false;
		if (res->next()) {
			if (res->getUInt("ex") == 1) {
				isExist = true;
			}
		}
		//如果不存在数据库操作表记录 则创建
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