#pragma once
namespace NetIOCP {
	class CSessionMgr : public CSingleton<CSessionMgr>, public ISessionManager {
		SINGLETION_FRIEND_CLASS_REGISTER(CSessionMgr)
	private:
		CSessionMgr() = default;
		CSessionMgr(const CSessionMgr&) = delete;
		CSessionMgr& operator=(const CSessionMgr&) = delete;
		~CSessionMgr();
	public: /* 对外开放的接口 */
		//注册外部对象实例 用于回调
		void registerHandle(IConnection* pconn) override { mpHandle = pconn; }
		//开始 iocp服务
		bool start(string ip, int port, int taskcount = 0) override;
		//iocp服务是否运行
		bool isStartup() override { return mbStartup; }
		//iocp服务是否停止
		bool isShutting() override { return mbShutting; }
		//停止
		void stop() override;
		//建立一个客户端socket去连接其它server
		ISession* Connect(string ip, int port) override;
	public:
		//接收到新的client socket连接
		void registerNewConn(ISession* netsession);
		//断开一个client socket连接
		void CloseConn(ISession* netsession);
	private:
		//开始前的初始化工作
		bool initBeforeStart(int taskcount);
		//开始前的WSASocket初始化工作
		bool initServerSocketBeforeStart(string& ip, int port);
		bool doStart();
	public:
		IOCompletionPort& GetIOCompletionPort() { return mIocp; }
		IConnectionManager* GetMonitor() { return mMonitor; }
		SOCKET ServerSocket() const { return mSocket; } //获取用于监听的socket
	private:
		IConnection* mpHandle{ nullptr };  //与外部交互的接口
	private:
		WSAInitializor mInit;  //winsock必须的初始化
		IOCompletionPort mIocp;  //iocp操作类的实例
		ITaskFactory* mTaskFactory{ nullptr }; //iocp线程管理对象
		IServerEvent* mServerEventHandler{ nullptr }; //内部处理的事件对象
		ISocketEvent* mSocketEventHandler{ nullptr }; //与外部交互的事件对象
		ISocketEventDispatcher* mSocketEventDispatcher{ nullptr }; //调度类对象
		IConnectionManager* mMonitor{ nullptr }; //监控事件对象
	private:
		sockaddr_in mAddress;  //服务器使用的socket ip和端口号
		SOCKET mSocket;	//服务器socket(用于监听)
		HANDLE mEventShutdown{ nullptr }; //用于关闭iocp的事件对象
		bool mbStartup{ false }; //是否在运行
		bool mbShutting{ false }; //是否在等待结束
	};
}