// FightServer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//�������е�������
void Destory(){
	//����û��˳��Ҫ��
	CProtoMgr::DestroyInstance();
	CSessionMgr::DestroyInstance();
}

//��ʼ������
void Init() {
	//��ȡ�����ļ�
	gConfigMgr = CConfigMgr::GetInstance();
	if (!gConfigMgr->Read(CONFIGPATH))
		return;
	//ע����Ϣ������
	CProtoMgr::GetInstance()->RegisterDefHandle(CGameServerMsgHandle::GetInstance());
	//��ʼ����������
	CSessionMgr::GetInstance()->Start("127.0.0.1", 8090);
}

int main()
{
	Init();
	while (true) {
		CSessionMgr::GetInstance()->Update();
	}
	//�ط�����������
	Destory();
    return 0;
}

