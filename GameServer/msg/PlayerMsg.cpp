#include "stdafx.h"

//������ע��������ҵ���Ϣ
void CPlayerMsg::Register() {
	auto pInstance = CProtoMgr::GetInstance();
	M_RegisterHandle(NET_C2S_Login);
	M_RegisterHandle(NET_C2S_CreateRole);
	//pInstance->RegisterProto(NET_C2S_Login, OnCreateNET_C2S_Login, OnHandleNET_C2S_Login);
}

bool CPlayerMsg::OnHandleNET_C2S_Login(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	NetLogin* pMsg = dynamic_cast<NetLogin*>(pBaseMsg);
#ifdef _DEBUG
	cout << pMsg->account().c_str() << " quest login" << endl;
#endif // _DEBUG
	//��һ�� ����Ƿ��Ѿ����ڴ�����
	string account = pMsg->account();
	CPlayer* pPlayer = CPlayerMgr::GetInstance()->GetPlayerByAccount(account);
	if (pPlayer != nullptr) {
		//�����ڴ������������
		pPlayer->mpSession = owner;
		owner->SetPlayer(pPlayer);
		return true;
	}
	//��Ҳ����ڴ��� �����ݿ����
	CSPNextData nkey;
	nkey.set_type(ENDKT_LoginPrepare);
	nkey.set_ivalue(owner->GetSessionId());
	CNextData* npdata = CNextDataMgr::GetInstance()->findTemp(nkey);
	if (npdata != nullptr) {
		//˵���Ѿ�ע����ɵ� ����Ҫ�ظ�ע��
		return true;
	}
	//����һ����ʱ�����ݵĿռ�
	npdata = CNextDataMgr::GetInstance()->createTemp(nkey);
	if (!npdata)  //�������ʧ�� ˵���������������� ��ʱ���õ�¼
		return false;
	//�������� �ڽ�ɫ������ɺ��ɽ�ɫʹ��
	npdata->AddData<INT>(pMsg->serverid());
	npdata->AddData<INT>(pMsg->platform());
	npdata->AddData<string>(pMsg->token());
	npdata->AddData<string>(account);
	//���ݿ����
	gDBLoadMgr->AddTask(new CPrepareLogin(account, pMsg->serverid(), owner));
	return true;
}

bool CPlayerMsg::OnHandleNET_C2S_CreateRole(CSession* owner, ::google::protobuf::Message* pBaseMsg) {
	NetCreateRole* pMsg = dynamic_cast<NetCreateRole*>(pBaseMsg);
	//������ǰ������������
	CSPNextData key;
	key.set_type(ENDKT_LoginPrepare);
	key.set_ivalue(owner->GetSessionId());
	CNextData* npdata = CNextDataMgr::GetInstance()->findTemp(key);
	if (!npdata) {
		//���next data ��ʧ�� �˴δ����½�ɫʧ��
		return false;
	}
	//ע�ᴴ����ɫ�¼�
	gDBSaveMgr->AddTask(new CCreateRole(
		gIdentify->NewId(EID_PlayerId)  //pid
		, pMsg->name().c_str()			//name
		, npdata->GetData<string>(3).c_str()  //account
		, npdata->GetData<INT>(0)		//serverid
		, npdata->GetData<INT>(1)		//platform
		, owner));	
	//������ɺ�ִ���������
	CNextDataMgr::GetInstance()->dirtyHandleTemp(key);
	return true;
}