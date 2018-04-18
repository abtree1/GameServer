#pragma once
namespace NetIOCP {
	class CSessionMgr : public CSingleton<CSessionMgr>, public ISessionManager {
		SINGLETION_FRIEND_CLASS_REGISTER(CSessionMgr)
	private:
		CSessionMgr() = default;
		CSessionMgr(const CSessionMgr&) = delete;
		CSessionMgr& operator=(const CSessionMgr&) = delete;
		~CSessionMgr();
	public: /* ���⿪�ŵĽӿ� */
		//ע���ⲿ����ʵ�� ���ڻص�
		void registerHandle(IConnection* pconn) override { mpHandle = pconn; }
		//��ʼ iocp����
		bool start(string ip, int port, int taskcount = 0) override;
		//iocp�����Ƿ�����
		bool isStartup() override { return mbStartup; }
		//iocp�����Ƿ�ֹͣ
		bool isShutting() override { return mbShutting; }
		//ֹͣ
		void stop() override;
		//����һ���ͻ���socketȥ��������server
		ISession* Connect(string ip, int port) override;
	public:
		//���յ��µ�client socket����
		void registerNewConn(ISession* netsession);
		//�Ͽ�һ��client socket����
		void CloseConn(ISession* netsession);
	private:
		//��ʼǰ�ĳ�ʼ������
		bool initBeforeStart(int taskcount);
		//��ʼǰ��WSASocket��ʼ������
		bool initServerSocketBeforeStart(string& ip, int port);
		bool doStart();
	public:
		IOCompletionPort& GetIOCompletionPort() { return mIocp; }
		IConnectionManager* GetMonitor() { return mMonitor; }
		SOCKET ServerSocket() const { return mSocket; } //��ȡ���ڼ�����socket
	private:
		IConnection* mpHandle{ nullptr };  //���ⲿ�����Ľӿ�
	private:
		WSAInitializor mInit;  //winsock����ĳ�ʼ��
		IOCompletionPort mIocp;  //iocp�������ʵ��
		ITaskFactory* mTaskFactory{ nullptr }; //iocp�̹߳������
		IServerEvent* mServerEventHandler{ nullptr }; //�ڲ�������¼�����
		ISocketEvent* mSocketEventHandler{ nullptr }; //���ⲿ�������¼�����
		ISocketEventDispatcher* mSocketEventDispatcher{ nullptr }; //���������
		IConnectionManager* mMonitor{ nullptr }; //����¼�����
	private:
		sockaddr_in mAddress;  //������ʹ�õ�socket ip�Ͷ˿ں�
		SOCKET mSocket;	//������socket(���ڼ���)
		HANDLE mEventShutdown{ nullptr }; //���ڹر�iocp���¼�����
		bool mbStartup{ false }; //�Ƿ�������
		bool mbShutting{ false }; //�Ƿ��ڵȴ�����
	};
}