// FightServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//析构所有单例对象
void Destory(){
	//析构没有顺序要求
	CProtoMgr::DestroyInstance();
	CSessionMgr::DestroyInstance();
}

//初始化函数
void Init() {
	//读取配置文件
	gConfigMgr = CConfigMgr::GetInstance();
	if (!gConfigMgr->Read(CONFIGPATH))
		return;
	//注册消息处理函数
	CProtoMgr::GetInstance()->RegisterDefHandle(CGameServerMsgHandle::GetInstance());
	//开始服务器监听
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8090);
}

int main()
{
	Init();
	while (true) {
		CSessionMgr::GetInstance()->Update();
	}
	//关服的清理流程
	Destory();
    return 0;
}

