// GameServer.cpp : 定义控制台应用程序的入口点。
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
	//销毁对象
	Destory();
    return 0;
}

