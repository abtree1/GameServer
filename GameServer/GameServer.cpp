// GameServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

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
//#ifdef _DEBUG
//	ConfigFile* file = IConfigMgr::GetInstance()->GetConfFile("test");
//	if (file) {
//		ConfDataBlock* block = file->GetCfg(3);
//		if (block) {
//			int id = block->GetIntValue("id");
//			string name = block->GetStringValue("name");
//			float money = block->GetFloatValue("money");
//			double power = block->GetDoubleValue("power");
//			char dtype = block->GetCharValue("type");
//			bool sex = block->GetBoolValue("sex");
//
//			cout << "id:" << id << " "
//				<< "name:" << name.c_str() << " "
//				<< "money:" << money << " "
//				<< "power:" << power << " "
//				<< "type:" << dtype << " "
//				<< "sex:" << std::boolalpha << sex << endl;
//		}
//	}
//#endif
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8080);
	while (true) {
		CSessionMgr::GetInstance()->Update();
		CThreadSave::GetInstance()->Finish();
	}
	//销毁对象
	Destory();
    return 0;
}