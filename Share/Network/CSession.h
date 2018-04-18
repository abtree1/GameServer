#pragma once
#ifdef _GAME_SERVER
class CPlayer;
#endif

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
	int GetSessionId() { return mpSession->GetSessionId(); }
private:
	//����ײ��session �����շ���Ϣ
	NetIOCP::ISession* mpSession;
#ifdef _GAME_SERVER
public:
	//Session ���� Player
	void SetPlayer(CPlayer* player) { mpPlayer = player; }
	//����player
	CPlayer* mpPlayer;
#endif
};
