// GameServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void Destory() {
	CTimerTaskMgr::DestroyInstance();
	CProtoMgr::DestroyInstance();
	CNextDataMgr::DestroyInstance();
	CSessionMgr::DestroyInstance();
	CThreadSave::DestroyInstance();
}

void Init() {
	CThreadSave::GetInstance()->HasTask();
}

int main()
{
	Init();
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8080);
	while (true) {
		CSessionMgr::GetInstance()->Update();
	}
	//���ٶ���
	Destory();
    return 0;
}

