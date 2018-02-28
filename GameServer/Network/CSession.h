#pragma once
class CPlayer;

class CSession {
public:
	CSession(NetIOCP::ISession* session);
	~CSession() = default;
public:
	//接收消息
	void Recv();
	//发送消息
	void Send(UINT type, ::google::protobuf::Message* msg);
public:
	//Session 关联 Player
	void SetPlayer(CPlayer* player) { mpPlayer = player; }
private:
	NetIOCP::ISession* mpSession;
	CPlayer* mpPlayer;
};
