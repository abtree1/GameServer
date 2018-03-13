// GameServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#ifdef _DEBUG
//���ڲ���
#include "tests/TestConfigs.h"
#endif

//�������еĵ�������
void Destory() {
	CTimerTaskMgr::DestroyInstance();
	CProtoMgr::DestroyInstance();
	CNextDataMgr::DestroyInstance();
	CSessionMgr::DestroyInstance();
	CThreadSave::DestroyInstance();
	IConfigMgr::DestroyInstance();
}

void Init() {
	//��ȡ�����ļ�
	IConfigMgr::GetInstance()->Read("../Configs");
	//�������ݿ����
	while (!CThreadSave::GetInstance()->IsConnectDB()) {
		//����߳�û�н��� �͵ȵ��߳�������ݿ�����
		if (CThreadSave::GetInstance()->IsClose())
			return;
		else
			this_thread::sleep_for(2s);
	}
	//ֻ��save�߳����ݿ����ӳɹ� load�̲߳����������ݿ�
	CThreadLoad::GetInstance()->IsConnectDB();
	//��ʼsocket����
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8080);
}

int main()
{
	Init();
#ifdef _DEBUG
	TestConfigs test;
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