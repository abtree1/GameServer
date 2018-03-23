// GameServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#ifdef _DEBUG
//���ڲ���
#include "tests/TestConfigs.h"
#endif

//�������еĵ�������
void Destory() {
	/************************************************************************
		����û�й�����˳��Ҫ��
	************************************************************************/
	if (gIdentify)
		delete gIdentify;
	CTimerTaskMgr::DestroyInstance();
	CProtoMgr::DestroyInstance();
	CNextDataMgr::DestroyInstance();
	CSessionMgr::DestroyInstance();
	CThreadSave::DestroyInstance();
	IConfigMgr::DestroyInstance();
}

void Init() {
	/************************************************************************
		��������ʱ�������
		config�����������������֮ǰ���
		DBSaveMgr ���ڸ��������ݿ�ṹ ����Ҫ��DBLoadMgrǰ���
	************************************************************************/
	//��ȡ�����ļ�
	gConfigMgr = IConfigMgr::GetInstance();
	if (!gConfigMgr->Read(CONFIGPATH))
		return;
	//�������ݿ����
	gDBSaveMgr = CThreadSave::GetInstance();
	while (!gDBSaveMgr->IsConnectDB()) {
		//����߳�û�н��� �͵ȵ��߳�������ݿ�����
		if (gDBSaveMgr->IsClose())
			return;
		else
			this_thread::sleep_for(2s);
	}
	//ֻ��save�߳����ݿ����ӳɹ� load�̲߳����������ݿ�
	gDBLoadMgr = CThreadLoad::GetInstance();
	gDBLoadMgr->IsConnectDB();
	//����id
	gIdentify->Load();
	//��ʼsocket����
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8080);
}

int main()
{
	Init();
#ifdef _DEBUG
	//TestConfigs test;
	//test.TestReadAuto();
#endif
	
	while (true) {
		CSessionMgr::GetInstance()->Update();
		CThreadSave::GetInstance()->Finish();
		CThreadLoad::GetInstance()->Finish();
	}
	//���ٶ���
	Destory();
    return 0;
}