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
		//��ʼ���̹߳�����
		mTaskFactory = new DefaultTaskFactory(taskcount);
		if (!mTaskFactory)
			return false;
		//��ʼ��������
		mSocketEventDispatcher = new TcpSocketEventDispatcher();
		if (!mSocketEventDispatcher)
			return false;
		//�ڲ�����¼� ֻ�����½����ӺͶϿ�����
		mMonitor = new TcpConnectionManager(mSocketEventDispatcher);
		if (!mMonitor)
			return false;
		//����iocp�¼���handler ���Ժ��ⲿ��������
		TcpSocketEventHandler *handle = new TcpSocketEventHandler();
		if (!handle)
			return false;
		mSocketEventHandler = handle;
		//�����ڲ��Լ��������¼��Ĵ��� Ŀǰû���ô�
		mServerEventHandler = new TcpSocketEventHandler::ServerEventHandler(*handle);
		if (!mServerEventHandler)
			return false;
		return true;
	}

	bool CSessionMgr::initServerSocketBeforeStart(string& ip, int port) {
		//���������TCPʹ�õ�IP�Ͷ˿ں�
		memset(&mAddress, 0, sizeof(mAddress));
		mAddress.sin_family = AF_INET;
		mAddress.sin_addr.S_un.S_addr = inet_addr(ip.c_str());
		mAddress.sin_port = htons(port);
		if (INADDR_NONE == mAddress.sin_addr.S_un.S_addr) {
			return false;
		}
		//����һ�����ص�IO��TCP socket ����������ʹ��
		//mSocket = WSAUtility::CreateOverlappedSocket<WSAUtility::TCP>(WSAUtility::TCP());
		mSocket = WSAUtility::CreateOverlappedSocket();
		if (INVALID_SOCKET == mSocket) {
			auto error = WSAGetLastError();
			cout << error << endl;
			return false;
		}
		//���ÿɸ�������
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
		//�ڲ��¼� ��ʼǰ�Ĵ���
		mServerEventHandler->PreStart();
		//��socket����
		if (SOCKET_ERROR == ::bind(mSocket, (sockaddr*)&mAddress, sizeof(mAddress))) {
			return false;
		}

		if (SOCKET_ERROR == ::listen(mSocket, SOMAXCONN)) {
			return false;
		}
		//������ɶ˿ھ�� ����socket
		if (!mIocp.GetSociateSocket(mSocket, nullptr)) {
			return false;
		}
		//ע��ص��¼�
		mSocketEventDispatcher->Register(mSocketEventHandler);
		//�����������߳�
		Statistics::AliveTask = mTaskFactory->Create(mSocketEventDispatcher);
		//��������ʼ������׼�����ܿͻ���socket���ӣ�
		mMonitor->Process();
		//����״̬
		mbStartup = true;
		//�ڲ�״̬�����¼�
		mServerEventHandler->PostStart();
		return true;
	}

	void CSessionMgr::stop() {
		if (!mbStartup)  //û�гɹ���ʼ �������
			return;
		if (mbShutting) //���ڵȴ����� �����ظ�����
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
		if (mpHandle) //֪ͨ�ⲿ �������ӵ���
			mpHandle->OnConnection(netsession);
	}

	void CSessionMgr::CloseConn(ISession* netsession) {
		if (mpHandle) //֪ͨ�ⲿ ��������Ѿ��Ͽ�
			mpHandle->OnDesconnection(netsession);
	}

	ISession* CSessionMgr::Connect(string ip, int port) {
		//���� client socket �����ӷ�����ʧ��
		Socket* cli = mMonitor->Connect(ip, port);
		if (!cli)
			return false;
		//��socket����ɶ˿ڰ�
		mIocp.GetSociateSocket(cli->GetSocket(), cli);
		//ע�����Ϣ
		IOBuffer* readBuf = new (BUFFER_SIZE) IOBuffer(BUFFER_SIZE, *cli);
		cli->Read(readBuf);
		//���سɹ�������client socket
		return cli;
	}
}