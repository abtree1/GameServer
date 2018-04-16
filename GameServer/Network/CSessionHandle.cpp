#include "stdafx.h"

void CSessionHandle::OnConnection(NetIOCP::ISession* pSession) {
	if (!pSession)
		return;
	CSessionMgr::GetInstance()->HandleConnect(pSession);
}

void CSessionHandle::OnDesconnection(NetIOCP::ISession* pSession) {
	if (!pSession)
		return;
	CSessionMgr::GetInstance()->HandleDisconnect(pSession);
}