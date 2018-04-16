#include "stdafx.h"

void thread_func(CThreadLoad* pMgr) {
	pMgr->ConnectDB();
	if (!pMgr->IsConnectDB()) {
		pMgr->Close();
		cerr << "Load Thread Connect DB Failed!" << endl;
		return;
	}
	//如果还没退出
	while (!pMgr->IsClose() || pMgr->HasTask()) {
		pMgr->Run();
	}
}

//保存单例的引用
//考虑到时序问题 全局变量的定义在GameServer的Init中统一实例化
CThreadLoad* gDBLoadMgr = nullptr;

CThreadLoad::CThreadLoad() {
	//开启线程
	std::thread th1(thread_func, this);
	th1.detach();
	//已经开始了子线程
	mState == EThreadState::ETS_Run;
}

CThreadLoad::~CThreadLoad() {
	//清理资源
	if (mpStmt)
		delete mpStmt;
	if (mpConn)
		delete mpConn;
	if (mpDriver)
		delete mpDriver;
}

void CThreadLoad::ConnectDB() {
	try {
		//非线程安全 获取driver
		mpDriver = sql::mysql::get_mysql_driver_instance();
		//获取数据库连接
		char buff[1024];
		ConfDataBlock* block = IConfigMgr::GetInstance()->GetPropFile("Setting");
		string dbip = block->GetStringValue("dbip");
		INT dbport = block->GetIntValue("dbport");
		CDBConfig& dbConf = IConfigMgr::GetInstance()->GetDBConf();
		string connStr = dbConf.GetConnStr();
		sprintf_s(buff, 1024, connStr.c_str(), dbip.c_str(), dbport);
		mpConn = mpDriver->connect(buff, block->GetStringValue("dbuser").c_str(), block->GetStringValue("dbpasswd").c_str());
		mpStmt = mpConn->createStatement();
		//连接数据库
		string dbname = block->GetStringValue("dbname");
		sprintf_s(buff, 1024, "use %s", dbname.c_str());
		mpStmt->execute(buff);
	}
	catch (const std::exception& e) {
		printf(e.what());
		return;
	}
	mbDBConnect = true;
}