#pragma once

//��ǰ����Ҫ��ʵ������net��ײ� ���ڵײ�ص�
class CSessionMgr : public CSingleton<CSessionMgr> {
	SINGLETION_FRIEND_CLASS_REGISTER(CSessionMgr)
private:
	CSessionMgr();
	~CSessionMgr();
public:
	//��������ʵ��
	void Start(string ip, int port);
	//��Ϊ�ͻ�������server
	int Connect(string ip, int port);
	//ע���µ�����
	bool HandleConnect(NetIOCP::ISession* pSession);
	//��ȡĳ��session
	CSession* FindSession(int sessionid);
	//�ر���������
	bool HandleDisconnect(NetIOCP::ISession* pSession);
	//ѭ����ȡ���յ�����Ϣ
	void Update();
private:
	//�������������Client Session
	map<int, CSession*> mpSessionVec;
	//���洫��net���ʵ������
	CSessionHandle mpSessionHandle;
	//����net ��Ķ���
	NetIOCP::ISessionManager* mpMgr;
};