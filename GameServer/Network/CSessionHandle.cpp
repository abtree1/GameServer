#include "stdafx.h"

void CSessionHandle::OnConnection(NetIOCP::ISession* pSession) {
	if (!pSession)
		return;
	CSessionMgr::GetInstance()->HandleConnect(pSession);
}