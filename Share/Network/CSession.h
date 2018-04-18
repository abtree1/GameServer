#pragma once
#ifdef _GAME_SERVER
class CPlayer;
#endif

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
	int GetSessionId() { return mpSession->GetSessionId(); }
private:
	//保存底层的session 用于收发消息
	NetIOCP::ISession* mpSession;
#ifdef _GAME_SERVER
public:
	//Session 关联 Player
	void SetPlayer(CPlayer* player) { mpPlayer = player; }
	//关联player
	CPlayer* mpPlayer;
#endif
};
