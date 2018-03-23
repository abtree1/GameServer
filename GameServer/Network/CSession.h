#pragma once
class CPlayer;

class CSession {
public:
	CSession(NetIOCP::ISession* session);
	~CSession() = default;
public:
	//������Ϣ
	void Recv();
	//������Ϣ
	void Send(UINT type, ::google::protobuf::Message* msg);
public:
	//Session ���� Player
	void SetPlayer(CPlayer* player) { mpPlayer = player; }
public:
	int GetSessionId() { return mpSession->GetSessionId(); }
private:
	//����ײ��session �����շ���Ϣ
	NetIOCP::ISession* mpSession;
	//����player
	CPlayer* mpPlayer;
};
