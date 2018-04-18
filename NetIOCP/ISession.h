#pragma once

#ifdef NETIOCP_EXPORTS
#define  DLL_CPP_API __declspec(dllexport)
#else
#define DLL_CPP_API __declspec(dllimport)
#endif
/*
	导出的接口 负责与外界交互
*/
namespace NetIOCP {
	//该类为内部传递给外部的session接口
	class DLL_CPP_API ISession {
	public:
		//发送数据用的接口
		virtual bool __stdcall OnSend(string&) = 0;
		//接收数据用的接口
		virtual bool __stdcall OnRecv(string&) = 0;
		//获取sessionid
		virtual int __stdcall GetSessionId() = 0;
		//断开连接
		virtual bool __stdcall Disconnect() = 0;
	};

	//该类用于外部继承
	class DLL_CPP_API IConnection {
	public:
		//新连接到来时的外部回调
		virtual void __stdcall OnConnection(ISession*) = 0;
		//连接关闭时的外部回调
		virtual void __stdcall OnDesconnection(ISession*) = 0;
	};
	/*
		session manager 供外部使用的接口
	*/
	class DLL_CPP_API ISessionManager {
	public:
		//向session manager注册外部对象，供回调时使用
		virtual void registerHandle(IConnection* pconn) = 0;
		/*
		开始iocp监听
		taskcount = 0 会根据系统创建服务线程
		*/
		virtual bool start(string ip, int port, int taskcount) = 0;
		//iocp是否已经开始运行
		virtual bool isStartup() = 0;
		//关闭iocp
		virtual void stop() = 0;
		//是否iocp处于关闭状态
		virtual bool isShutting() = 0;
		//建立对一个server的连接
		virtual ISession* Connect(string ip, int port) = 0;
	};
	//外部用于获取session manager的对象实例
	extern DLL_CPP_API ISessionManager* __stdcall gGetSessionMgr();
	extern DLL_CPP_API void __stdcall gDestorySessionMgr();
}
