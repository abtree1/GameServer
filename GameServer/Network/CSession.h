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
private:
	NetIOCP::ISession* mpSession;
	CPlayer* mpPlayer;
};
