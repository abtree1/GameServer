#pragma once

#ifdef NETIOCP_EXPORTS
#define  DLL_CPP_API __declspec(dllexport)
#else
#define DLL_CPP_API __declspec(dllimport)
#endif

namespace NetIOCP {
	//该类为内部传递给外部的session接口
	class DLL_CPP_API ISession {
	public:
		virtual bool __stdcall OnSend(string&) = 0;
		virtual bool __stdcall OnRecv(string&) = 0;
	};

	//该类用于外部继承
	class DLL_CPP_API IConnection {
	public:
		virtual void __stdcall OnConnection(ISession*) = 0;
	};

	class DLL_CPP_API ISessionManager {
	public:
		virtual void registerHandle(IConnection* pconn) = 0;
		/*
		taskcount = 0 会根据系统创建服务线程
		*/
		virtual bool start(string ip, int port, int taskcount) = 0;
		virtual bool isStartup() = 0;
		virtual void stop() = 0;
		virtual bool isShutting() = 0;
	};

	extern DLL_CPP_API ISessionManager* __stdcall gGetSessionMgr();
	extern DLL_CPP_API void __stdcall gDestorySessionMgr();
}
