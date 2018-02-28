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
		mTaskFactory = new DefaultTaskFactory(taskcount);
		if (!mTaskFactory)
			return false;
		mSocketEventDispatcher = new TcpSocketEventDispatcher();
		if (!mSocketEventDispatcher)
			return false;
		mMonitor = new TcpConnectionManager(mSocketEventDispatcher);
		if (!mMonitor)
			return false;
		TcpSocketEventHandler *handle = new TcpSocketEventHandler();
		if (!handle)
			return false;
		mSocketEventHandler = handle;
		mServerEventHandler = new TcpSocketEventHandler::ServerEventHandler(*handle);
		if (!mServerEventHandler)
			return false;
		return true;
	}

	bool CSessionMgr::initServerSocketBeforeStart(string& ip, int port) {
		memset(&mAddress, 0, sizeof(mAddress));
		mAddress.sin_family = AF_INET;
		mAddress.sin_addr.S_un.S_addr = inet_addr(ip.c_str());
		if (INADDR_NONE == mAddress.sin_addr.S_un.S_addr) {
			return false;
		}

		mSocket = WSAUtility::CreateOverlappedSocket(WSAUtility::TCP());
		if (INVALID_SOCKET == mSocket) {
			return false;
		}

		BOOL bReuse = TRUE;
		int ret = setsockopt(mSocket, SOL_SOCKET, SO_REUSEADDR, (const char*)&bReuse, sizeof(bReuse));
		if (SOCKET_ERROR == ret) {
			return false;
		}

		mAddress.sin_port = htons(port);
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
		mServerEventHandler->PreStart();

		if (SOCKET_ERROR == ::bind(mSocket, (sockaddr*)&mAddress, sizeof(mAddress))) {
			return false;
		}

		if (SOCKET_ERROR == ::listen(mSocket, SOMAXCONN)) {
			return false;
		}

		if (!mIocp.AssociateSocket(mSocket, nullptr)) {
			return false;
		}

		mSocketEventDispatcher->Register(mSocketEventHandler);
		Statistics::AliveTask = mTaskFactory->Create(mSocketEventDispatcher);
		mMonitor->Process();
		mbStartup = true;
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
		if (mpHandle)
			mpHandle->OnConnection(netsession);
	}
}