#include "stdafx.h"

void thread_func(CThreadSave* pMgr) {
	pMgr->ConnectDB();
	if (!pMgr->IsConnectDB()) {
		pMgr->Close();
		cerr << "Save Thread Connect DB Failed!" << endl;
		return;
	}
	//如果还没退出
	if (!pMgr->IsClose() || pMgr->HasTask()) {
		pMgr->Run();
	}
}

//保存单例的引用
//考虑到时序问题 全局变量的定义在GameServer的Init中统一实例化
CThreadSave* gDBSaveMgr = nullptr;

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
	//检查并创建数据库基本结构
	if (!CheckDBInit())
		return;
	//检查并执行数据库更新
	if (!StructDB())
		return;
	mbDBConnect = true;
}

bool CThreadSave::CheckDBInit() {
	try {
		//非线程安全 获取driver
		mpDriver = sql::mysql::get_mysql_driver_instance();
		//获取数据库连接
		char buff[1024];
		ConfDataBlock* block = gConfigMgr->GetPropFile("Setting");
		string dbip = block->GetStringValue("dbip");
		INT dbport = block->GetIntValue("dbport");
		CDBConfig& dbConf = IConfigMgr::GetInstance()->GetDBConf();
		string connStr = dbConf.GetConnStr();
		sprintf_s(buff, 1024, connStr.c_str(), dbip.c_str(), dbport);
		mpConn = mpDriver->connect(buff, block->GetStringValue("dbuser").c_str(), block->GetStringValue("dbpasswd").c_str());
		mpStmt = mpConn->createStatement();
		//连接数据库
		string dbname = block->GetStringValue("dbname");
		string createdb = dbConf.GetDBCreate();
		sprintf_s(buff, 1024, createdb.c_str(), dbname.c_str());
		mpStmt->execute(buff);
		sprintf_s(buff, 1024, "use %s", dbname.c_str());
		mpStmt->execute(buff);
		//查看表信息
		string altertable = block->GetStringValue("dblogtable");
		string alterstr = dbConf.GetHasAlter();
		sprintf_s(buff, 1024, alterstr.c_str(), altertable.c_str(), dbname.c_str());
		sql::ResultSet* res = mpStmt->executeQuery(buff);
		bool isExist = false;
		if (res->next()) {
			if (res->getUInt("ex") == 1) {
				isExist = true;
			}
		}
		if (!isExist) {
			//如果不存在数据库操作表记录 则创建
			string createtable = dbConf.GetAlterCreate();
			sprintf_s(buff, 1024, createtable.c_str(), altertable.c_str());
			mpStmt->execute(buff);
		}
	}
	catch (const std::exception& e) {
		printf(e.what());
		return false;
	}
	return true;
}

bool CThreadSave::StructDB() {
	//查询所有的已经更新的记录
	CDBConfig& conf = IConfigMgr::GetInstance()->GetDBConf();
	string dbalter = IConfigMgr::GetInstance()->GetSettingValue<string>("dblogtable");
	char buff[1024];
	sprintf_s(buff, 1024, conf.GetQueryAlter().c_str(), dbalter.c_str());
	try {
		sql::ResultSet* res = mpStmt->executeQuery(buff);
		set<INT> mergeVec;
		while (res->next()) {
			mergeVec.insert(res->getInt("id"));
		}
		res->close();
		//执行更新操作
		bool last = mpConn->getAutoCommit();
		mpConn->setAutoCommit(false);
		vector<INT> exected;  //保存这次执行的更新
		try {
			map<INT, string> merges = conf.GetMerge();
			for (auto it : merges) {
				if (mergeVec.find(it.first) != mergeVec.end())
					continue;
				//执行这条更新
				mpStmt->execute(it.second.c_str());
				//记录
				exected.push_back(it.first);
			}
			if (!exected.empty()) {
				sprintf_s(buff, 1024, "INSERT INTO `%s`(id) VALUES(?);", dbalter.c_str());
				//完成执行后需要更新记录日志
				auto* prep_stmt = mpConn->prepareStatement(buff);
				for (auto &id : exected)
				{
					prep_stmt->setInt(1, id);
					prep_stmt->execute();
				}
				//string update = "INSERT INT `%s`(id) VALUES(%d)";
				//string tail = ",(%d)";
				////拼凑更新字符串
				//for (int i = 0; i < exected.size(); ++i) {
				//	if (i == 0) {
				//		sprintf_s(buff, 1024, update.c_str(), dbalter.c_str(), exected[i]);
				//		update = string(buff);
				//	}
				//	else {
				//		sprintf_s(buff, 1024, tail.c_str(), exected[i]);
				//		update += string(buff);
				//	}
				//}
			}
			mpConn->commit();
		}
		catch (sql::SQLException & e) {
			mpConn->rollback();
			printf(e.what());
		}
		mpConn->setAutoCommit(last);
	}
	catch (const std::exception& e) {
		printf(e.what());
		return false;
	}
	return true;
}