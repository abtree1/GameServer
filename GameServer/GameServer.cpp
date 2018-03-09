// GameServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

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
	//���ٶ���
	Destory();
    return 0;
}