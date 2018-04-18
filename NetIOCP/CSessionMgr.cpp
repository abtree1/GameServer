#include "stdafx.h"

namespace NetIOCP {
	CSessionMgr::~CSessionMgr() {
		::closesocket(mSocket);
		mSocket = INVALID_SOCKET;
		::CloseHandle(mEventShutdown);
		if (mTaskFactory)
			delete mTaskFactory;
		if (mServerEventHandler)
			delete mServerEventHandler;
		if (mSocketEventHandler)
			delete mSocketEventHandler;
		if (mSocketEventDispatcher)
			delete mSocketEventDispatcher;
		if (mMonitor)
			delete mMonitor;
	}

	bool CSessionMgr::initBeforeStart(int taskcount) {
		//初始化线程管理类
		mTaskFactory = new DefaultTaskFactory(taskcount);
		if (!mTaskFactory)
			return false;
		//初始化调度类
		mSocketEventDispatcher = new TcpSocketEventDispatcher();
		if (!mSocketEventDispatcher)
			return false;
		//内部监控事件 只处理新建连接和断开连接
		mMonitor = new TcpConnectionManager(mSocketEventDispatcher);
		if (!mMonitor)
			return false;
		//处理iocp事件的handler 可以和外部交换数据
		TcpSocketEventHandler *handle = new TcpSocketEventHandler();
		if (!handle)
			return false;
		mSocketEventHandler = handle;
		//用于内部自己产生的事件的处理 目前没有用处
		mServerEventHandler = new TcpSocketEventHandler::ServerEventHandler(*handle);
		if (!mServerEventHandler)
			return false;
		return true;
	}

	bool CSessionMgr::initServerSocketBeforeStart(string& ip, int port) {
		//处理服务器TCP使用的IP和端口号
		memset(&mAddress, 0, sizeof(mAddress));
		mAddress.sin_family = AF_INET;
		mAddress.sin_addr.S_un.S_addr = inet_addr(ip.c_str());
		mAddress.sin_port = htons(port);
		if (INADDR_NONE == mAddress.sin_addr.S_un.S_addr) {
			return false;
		}
		//创建一个带重叠IO的TCP socket 服务器监听使用
		//mSocket = WSAUtility::CreateOverlappedSocket<WSAUtility::TCP>(WSAUtility::TCP());
		mSocket = WSAUtility::CreateOverlappedSocket();
		if (INVALID_SOCKET == mSocket) {
			auto error = WSAGetLastError();
			cout << error << endl;
			return false;
		}
		//设置可复用属性
		BOOL bReuse = TRUE;
		int ret = setsockopt(mSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&bReuse, sizeof(bReuse));
		if (SOCKET_ERROR == ret) {
			return false;
		}
		return true;
	}

	bool CSessionMgr::start(string ip, int port, int taskcount) {
		if (!initBeforeStart(taskcount))
			return false;
		if (!initServerSocketBeforeStart(ip, port))
			return false;
		return doStart();
	}

	bool CSessionMgr::doStart() {
		//内部事件 开始前的处理
		mServerEventHandler->PreStart();
		//绑定socket监听
		if (SOCKET_ERROR == ::bind(mSocket, (sockaddr*)&mAddress, sizeof(mAddress))) {
			return false;
		}

		if (SOCKET_ERROR == ::listen(mSocket, SOMAXCONN)) {
			return false;
		}
		//创建完成端口句柄 并绑定socket
		if (!mIocp.GetSociateSocket(mSocket, nullptr)) {
			return false;
		}
		//注册回调事件
		mSocketEventDispatcher->Register(mSocketEventHandler);
		//创建工作器线程
		Statistics::AliveTask = mTaskFactory->Create(mSocketEventDispatcher);
		//监听器开始监听（准备接受客户端socket连接）
		mMonitor->Process();
		//设置状态
		mbStartup = true;
		//内部状态更新事件
		mServerEventHandler->PostStart();
		return true;
	}

	void CSessionMgr::stop() {
		if (!mbStartup)  //没有成功开始 不需结束
			return;
		if (mbShutting) //正在等待结束 无需重复结束
			return;
		mServerEventHandler->PreShutdown();

		Socket* mock = nullptr;
		shared_ptr<IOBuffer> mockBuf = make_shared<IOBuffer>(1, *mock);
		mockBuf->SetOperation(IO_Operation::IO_Termination);

		int numberOfTask = mTaskFactory->GetTaskCount();
		for (unsigned int i = 0; i < numberOfTask; ++i) {
			mIocp.PostQueuedCompletionStatus(0, nullptr, mockBuf.get());
		}

		HANDLE timer = ::CreateEvent(NULL, TRUE, FALSE, NULL);
		while (true)
		{
			::WaitForSingleObject(timer, 500);
			// when to break
			if (0 == ::InterlockedCompareExchange(
				&Statistics::AliveTask,
				Statistics::AliveTask,
				Statistics::AliveTask))
			{
				break;
			}
		}
		::CloseHandle(timer);

		mServerEventHandler->PostShutdown();

		::SetEvent(mEventShutdown);

		mbShutting = true;
		mbStartup = false;
	}

	void CSessionMgr::registerNewConn(ISession* netsession) {
		if (mpHandle) //通知外部 有新连接到来
			mpHandle->OnConnection(netsession);
	}

	void CSessionMgr::CloseConn(ISession* netsession) {
		if (mpHandle) //通知外部 这个连接已经断开
			mpHandle->OnDesconnection(netsession);
	}

	ISession* CSessionMgr::Connect(string ip, int port) {
		//创建 client socket 并连接服务器失败
		Socket* cli = mMonitor->Connect(ip, port);
		if (!cli)
			return false;
		//将socket与完成端口绑定
		mIocp.GetSociateSocket(cli->GetSocket(), cli);
		//注册读消息
		IOBuffer* readBuf = new (BUFFER_SIZE) IOBuffer(BUFFER_SIZE, *cli);
		cli->Read(readBuf);
		//返回成功创建的client socket
		return cli;
	}
}