// NetIOCP.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

namespace NetIOCP {
	DLL_CPP_API ISessionManager* __stdcall gGetSessionMgr() {
		return CSessionMgr::GetInstance();
	}

	DLL_CPP_API void __stdcall gDestorySessionMgr() {
		CSessionMgr::DestroyInstance();
	}
}