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
	CThreadSave::GetInstance()->Finish();
}

int main()
{
	Init();
#ifdef _DEBUG
	TestConfigs test;
	test.TestLanguage();
#endif
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8080);
	while (true) {
		CSessionMgr::GetInstance()->Update();
		CThreadSave::GetInstance()->Finish();
	}
	//���ٶ���
	Destory();
    return 0;
}