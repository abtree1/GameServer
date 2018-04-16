#pragma once

//ȫ�����ݿ�Id����
class CLoadIds : public IDBTask {
public:
	CLoadIds();
public:
	void Run() override;
	void Finish() override;
};
//�洢timertask
class CSaveTimerTask : public IDBTask {
public:
	CSaveTimerTask();
public:
	void Run() override;
	void Finish() override;
};
//����timertask
class CLoadTimerTask : public IDBTask {
public:
	CLoadTimerTask();
public:
	void Run() override;
	void Finish() override;
};
//��ҵ�¼ǰ��׼������
class CPrepareLogin : public IDBTask {
public:
	CPrepareLogin(string& account, u32 serverid, CSession* session);
public:
	void Run() override;
	void Finish() override;
private:
	u32 mServerId{ 0 };			//���ѡ��ķ�����id
	bool mHasPlayer{ false };	//�Ƿ��Ѿ�������ɫ
	u32 mPlayerId{ 0 };		//�����Ľ�ɫ�����id
	CSession* mpSession{ nullptr }; //session���ͻ��ˣ�
};
//������ɫ
class CCreateRole : public IDBTask {
public:
	CCreateRole(u32 pid, string name, string account, u32 serverid, int platform, CSession* session);
public:
	void Run() override;
	void Finish() override;
private:
	u32 mPid{ 0 };					//������ɫ���õ�pid
	CSession* mpSession{ nullptr }; //�ͻ���session
	bool mSuccess{ false }; //�Ƿ񴴽��ɹ�
};
//�������
class CLoadPlayer : public IDBTask {
public:
	CLoadPlayer(u32 pid, CSession* session);
public:
	void Run() override;
	void Finish() override;
private:
	CPlayer* mpPlayer{ nullptr };  //�������ݵ����
	bool mSuccess{ false }; //�Ƿ�ɹ�
};