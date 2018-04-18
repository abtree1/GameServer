#pragma once

class CSessionHandle : public NetIOCP::IConnection {
public:
	CSessionHandle() = default;
	~CSessionHandle() = default;
public:
	void __stdcall OnConnection(NetIOCP::ISession* pSession) override;
	void __stdcall OnDesconnection(NetIOCP::ISession* pSession) override;

};