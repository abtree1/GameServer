// GameServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#ifdef _DEBUG
//用于测试
#include "tests/TestConfigs.h"
#endif

//析构所有的单例对象
void Destory() {
	CTimerTaskMgr::DestroyInstance();
	CProtoMgr::DestroyInstance();
	CNextDataMgr::DestroyInstance();
	CSessionMgr::DestroyInstance();
	CThreadSave::DestroyInstance();
	IConfigMgr::DestroyInstance();
}

void Init() {
	//读取配置文件
	IConfigMgr::GetInstance()->Read("../Configs");
	//开启数据库进程
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
	//销毁对象
	Destory();
    return 0;
}