#pragma once
namespace NetIOCP {
	class CSessionMgr : public CSingleton<CSessionMgr>, public ISessionManager {
		SINGLETION_FRIEND_CLASS_REGISTER(CSessionMgr)
	private:
		CSessionMgr() = default;
		CSessionMgr(const CSessionMgr&) = delete;
		CSessionMgr& operator=(const CSessionMgr&) = delete;
		~CSessionMgr();
	public:
		void registerHandle(IConnection* pconn) override { mpHandle = pconn; }
		bool start(string ip, int port, int taskcount = 0) override;
		bool isStartup() override { return mbStartup; }
		bool isShutting() override { return mbShutting; }
		void stop() override;
		void registerNewConn(ISession* netsession);
	private:
		bool initBeforeStart(int taskcount);
		bool initServerSocketBeforeStart(string& ip, int port);
		bool doStart();
	public:
		IOCompletionPort& GetIOCompletionPort() { return mIocp; }
		IConnectionManager* GetMonitor() { return mMonitor; }
		SOCKET AsSocket() const { return mSocket; }
	private:
		IConnection* mpHandle{ nullptr };  //与外部交互的接口
	private:
		WSAInitializor mInit;
		IOCompletionPort mIocp;
		ITaskFactory* mTaskFactory{ nullptr };
		IServerEvent* mServerEventHandler{ nullptr };
		ISocketEvent* mSocketEventHandler{ nullptr };
		ISocketEventDispatcher* mSocketEventDispatcher{ nullptr };
		IConnectionManager* mMonitor{ nullptr };
	private:
		sockaddr_in mAddress;
		SOCKET mSocket;
		HANDLE mEventShutdown{ nullptr };
		bool mbStartup{ false };
		bool mbShutting{ false };
	};
}