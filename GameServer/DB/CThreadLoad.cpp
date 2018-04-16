#include "stdafx.h"

void thread_func(CThreadLoad* pMgr) {
	pMgr->ConnectDB();
	if (!pMgr->IsConnectDB()) {
		pMgr->Close();
		cerr << "Load Thread Connect DB Failed!" << endl;
		return;
	}
	//�����û�˳�
	while (!pMgr->IsClose() || pMgr->HasTask()) {
		pMgr->Run();
	}
}

//���浥��������
//���ǵ�ʱ������ ȫ�ֱ����Ķ�����GameServer��Init��ͳһʵ����
CThreadLoad* gDBLoadMgr = nullptr;

CThreadLoad::CThreadLoad() {
	//�����߳�
	std::thread th1(thread_func, this);
	th1.detach();
	//�Ѿ���ʼ�����߳�
	mState == EThreadState::ETS_Run;
}

CThreadLoad::~CThreadLoad() {
	//������Դ
	if (mpStmt)
		delete mpStmt;
	if (mpConn)
		delete mpConn;
	if (mpDriver)
		delete mpDriver;
}

void CThreadLoad::ConnectDB() {
	try {
		//���̰߳�ȫ ��ȡdriver
		mpDriver = sql::mysql::get_mysql_driver_instance();
		//��ȡ���ݿ�����
		char buff[1024];
		ConfDataBlock* block = IConfigMgr::GetInstance()->GetPropFile("Setting");
		string dbip = block->GetStringValue("dbip");
		INT dbport = block->GetIntValue("dbport");
		CDBConfig& dbConf = IConfigMgr::GetInstance()->GetDBConf();
		string connStr = dbConf.GetConnStr();
		sprintf_s(buff, 1024, connStr.c_str(), dbip.c_str(), dbport);
		mpConn = mpDriver->connect(buff, block->GetStringValue("dbuser").c_str(), block->GetStringValue("dbpasswd").c_str());
		mpStmt = mpConn->createStatement();
		//�������ݿ�
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