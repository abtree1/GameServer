// NetIOCP.cpp : 定义 DLL 应用程序的导出函数。
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