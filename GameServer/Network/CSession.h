#pragma once

class CSession {
public:
	CSession(NetIOCP::ISession* session);
	~CSession() = default;
public:
	void Recv();
	void Send(UINT type, ::google::protobuf::Message* msg);
private:
	NetIOCP::ISession* mpSession;
};
