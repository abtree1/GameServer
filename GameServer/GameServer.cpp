// GameServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void Destory() {
	CTimerTaskMgr::DestroyInstance();
	CProtoMgr::DestroyInstance();
	CNextDataMgr::DestroyInstance();
	CSessionMgr::DestroyInstance();
}

int main()
{
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8080);
	while (true) {
		CSessionMgr::GetInstance()->Update();
	}
	//���ٶ���
	Destory();
    return 0;
}

