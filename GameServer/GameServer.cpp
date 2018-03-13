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
	while (!CThreadSave::GetInstance()->IsConnectDB()) {
		//如果线程没有结束 就等到线程完成数据库连接
		if (CThreadSave::GetInstance()->IsClose())
			return;
		else
			this_thread::sleep_for(2s);
	}
	//只有save线程数据库连接成功 load线程才能连接数据库
	CThreadLoad::GetInstance()->IsConnectDB();
	//开始socket监听
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
	//销毁对象
	Destory();
    return 0;
}