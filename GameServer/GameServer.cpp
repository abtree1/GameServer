// GameServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8080);
	while (true) {
		CSessionMgr::GetInstance()->Update();
	}
	//���ٶ���
	CSessionMgr::DestroyInstance();
    return 0;
}

