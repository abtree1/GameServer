#pragma once

namespace NetIOCP {
	class Socket : public ISession {
	private:
		enum SocketStatus
		{
			DenyReceive = SD_RECEIVE,
			DenySend = SD_SEND,
			DenySendnReceive = SD_BOTH,
			Closed = DenySendnReceive + 1,
			Normal = Closed + 1
		};
		/*protected:
			class SocketEventHandler : public ISocketEvent {
			public:
				using ISocketEvent::ISocketEvent;
			public:
				virtual void PreAccept(Socket& socket, IOBuffer& buffer) {}
				virtual void PostAccept(Socket& socket, IOBuffer& buffer) {}
				virtual void OnError(Socket& socket) {}
				virtual void PostClose(Socket& socket) {}
				virtual void PostRead(Socket& socket, IOBuffer& buffer);
				virtual void PostWrite(Socket& socket, IOBuffer& buffer);
				virtual void PreClose(Socket& socket) {}
				virtual void PreRead(Socket& socket, IOBuffer& buffer);
				virtual void PreWrite(Socket& socket, IOBuffer& buffer);
			};*/
	public:
		Socket(SOCKET socket, ISocketEventDispatcher* dispatcher, const sockaddr_in& addr);
		Socket(SOCKET socket, ISocketEventDispatcher* dispatcher);
		Socket(const Socket&) = delete;
		Socket& operator=(const Socket&) = delete;
		virtual ~Socket();
	public:
		bool __stdcall OnSend(string& data) override;
		bool __stdcall OnRecv(string& data) override;
		int __stdcall GetSessionId() override { return mSocket; }
		bool __stdcall Disconnect() override;
	public:
		SOCKET GetSocket() const { return mSocket; }  //��ȡsocket
		void Close();
		void OnReadZeroByte(IOBuffer* buffer);
		sockaddr_in* GetPeerAddress() { return &mPeer; }
		void SetPeerAddress(sockaddr_in& addr) { mPeer = addr; }
		/*long IncreaseRef() {
			return ::InterlockedIncrement(&mPendingReads);
		}*/
		/*long DecreaseRef() {
			long ref = ::InterlockedDecrement(&mReference);
			if (0 == ref) {
				delete this;
			}
			return ref;
		}*/
		bool IsConnected(unsigned long& time);
		void pushInReads(IOBuffer* buffer);
		bool Read(IOBuffer* buffer);
		void Shutdown(int how);
		//void Write(IOBuffer* buffer);
		//void Write(const vector<IOBuffer*>& buffers);
		void WriteNext();
		//static void RegisterEventHandler(ISocketEventDispatcher& dispatcher);
	protected:
		void Init(SOCKET socket);
	private:
		bool DoWrite(string& send);
	private:
		static char* mStatusDescription[];
	protected:
		SocketStatus mStatus;
		sockaddr_in mPeer; //һ��socket��ַ����Ҫ�����ͻ���ʱ���ӷ������ĵ�ַ
		SOCKET mSocket;   //����Ŀͻ���socket������ͨ�ţ�
		ISocketEventDispatcher* mDispatcher;
		moodycamel::ConcurrentQueue<string> mPendingWrites;   //��Ϣд�Ķ���
		moodycamel::ConcurrentQueue<string> mPendingReadQueue; //��Ϣ���Ķ���
		//long mPendingReads{ 0 };
		//long mReference{ 0 };
		long mIsClosed{ 0 };
	protected:
		//���ڱ��滹û�н����������
		string mCliDataTemp{""}; //��Ϣ����
		int mMaxSize{0}; //����Ϣ���ܳ���
		int mCurSize{0}; //��ǰ�Ѿ����յĳ���
	};
}