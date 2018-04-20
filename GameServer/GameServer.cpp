// GameServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#ifdef _DEBUG
//用于测试
#include "tests/TestConfigs.h"
#endif

//析构所有的单例对象
void Destory() {
	/************************************************************************
		析构没有关联的顺序要求
	************************************************************************/
	if (gIdentify)
		delete gIdentify;
	CTimerTaskMgr::DestroyInstance();
	CProtoMgr::DestroyInstance();
	CNextDataMgr::DestroyInstance();
	CSessionMgr::DestroyInstance();
	CThreadSave::DestroyInstance();
	CConfigMgr::DestroyInstance();
}

void Init() {
	/************************************************************************
		这里是有时序问题的
		config必须在其它操作完成之前完成
		DBSaveMgr 由于负责检查数据库结构 故需要在DBLoadMgr前完成
	************************************************************************/
	//读取配置文件
	gConfigMgr = CConfigMgr::GetInstance();
	if (!gConfigMgr->Read(CONFIGPATH))
		return;
	//开启数据库进程
	gDBSaveMgr = CThreadSave::GetInstance();
	while (!gDBSaveMgr->IsConnectDB()) {
		//如果线程没有结束 就等到线程完成数据库连接
		if (gDBSaveMgr->IsClose())
			return;
		else
			this_thread::sleep_for(2s);
	}
	//只有save线程数据库连接成功 load线程才能连接数据库
	gDBLoadMgr = CThreadLoad::GetInstance();
	gDBLoadMgr->IsConnectDB();
	//加载id
	gIdentify->Load();
	
	//注册消息处理函数
	CProtoMgr::GetInstance()->RegisterDefHandle(CPlayerMsg::GetInstance());
	//开始socket监听
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8080);

	//连接其它服务器
	auto fightServerId = CSessionMgr::GetInstance()->Connect("127.0.0.1", 8090);
	//注册消息处理函数
	CFightServerMsg::GetInstance()->mSessionId = fightServerId;
	CProtoMgr::GetInstance()->RegisterHandle(fightServerId, CFightServerMsg::GetInstance());
	//CFightServerMsg::Register(fightServerId);
}

int main()
{
	Init();
//#ifdef _DEBUG
	//TestConfigs test;
	//test.TestConf();
	//test.TestProp();
//#endif
	//测试向FightServer发送消息
	/*CSession* session = CSessionMgr::GetInstance()->FindSession(gFightServerId);
	if (session) {
		session->Send(NET_G2F_Init, nullptr);
	}*/
	//主循环
	while (true) {
		CSessionMgr::GetInstance()->Update();
		CThreadSave::GetInstance()->Finish();
		CThreadLoad::GetInstance()->Finish();
	}
	//销毁对象
	Destory();
    return 0;
}