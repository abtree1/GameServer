#include "stdafx.h"

void thread_func(CThreadSave* pMgr) {
	pMgr->ConnectDB();
	if (!pMgr->IsConnectDB()) {
		pMgr->Close();
		cerr << "Save Thread Connect DB Failed!" << endl;
		return;
	}
	//�����û�˳�
	if (!pMgr->IsClose() || pMgr->HasTask()) {
		pMgr->Run();
	}
}

//���浥��������
//���ǵ�ʱ������ ȫ�ֱ����Ķ�����GameServer��Init��ͳһʵ����
CThreadSave* gDBSaveMgr = nullptr;

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
	//��鲢�������ݿ�����ṹ
	if (!CheckDBInit())
		return;
	//��鲢ִ�����ݿ����
	if (!StructDB())
		return;
	mbDBConnect = true;
}

bool CThreadSave::CheckDBInit() {
	try {
		//���̰߳�ȫ ��ȡdriver
		mpDriver = sql::mysql::get_mysql_driver_instance();
		//��ȡ���ݿ�����
		char buff[1024];
		ConfDataBlock* block = gConfigMgr->GetPropFile("Setting");
		string dbip = block->GetStringValue("dbip");
		INT dbport = block->GetIntValue("dbport");
		CDBConfig& dbConf = IConfigMgr::GetInstance()->GetDBConf();
		string connStr = dbConf.GetConnStr();
		sprintf_s(buff, 1024, connStr.c_str(), dbip.c_str(), dbport);
		mpConn = mpDriver->connect(buff, block->GetStringValue("dbuser").c_str(), block->GetStringValue("dbpasswd").c_str());
		mpStmt = mpConn->createStatement();
		//�������ݿ�
		string dbname = block->GetStringValue("dbname");
		string createdb = dbConf.GetDBCreate();
		sprintf_s(buff, 1024, createdb.c_str(), dbname.c_str());
		mpStmt->execute(buff);
		sprintf_s(buff, 1024, "use %s", dbname.c_str());
		mpStmt->execute(buff);
		//�鿴����Ϣ
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
			//������������ݿ�������¼ �򴴽�
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
	//��ѯ���е��Ѿ����µļ�¼
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
		//ִ�и��²���
		bool last = mpConn->getAutoCommit();
		mpConn->setAutoCommit(false);
		vector<INT> exected;  //�������ִ�еĸ���
		try {
			map<INT, string> merges = conf.GetMerge();
			for (auto it : merges) {
				if (mergeVec.find(it.first) != mergeVec.end())
					continue;
				//ִ����������
				mpStmt->execute(it.second.c_str());
				//��¼
				exected.push_back(it.first);
			}
			if (!exected.empty()) {
				sprintf_s(buff, 1024, "INSERT INTO `%s`(id) VALUES(?);", dbalter.c_str());
				//���ִ�к���Ҫ���¼�¼��־
				auto* prep_stmt = mpConn->prepareStatement(buff);
				for (auto &id : exected)
				{
					prep_stmt->setInt(1, id);
					prep_stmt->execute();
				}
				//string update = "INSERT INT `%s`(id) VALUES(%d)";
				//string tail = ",(%d)";
				////ƴ�ո����ַ���
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