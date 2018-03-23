#include "stdafx.h"

namespace NetIOCP {
	char* Socket::mStatusDescription[] = {
		"The socket deny receive.",
		"The socket deny send.",
		"The socket deny receive and send.",
		"The socket is closed."
	};

	Socket::Socket(SOCKET socket, ISocketEventDispatcher* dispatcher, const sockaddr_in& addr) 
		:mPeer(addr)
		,mDispatcher(dispatcher)
		{
		Init(socket);
	}

	Socket::Socket(SOCKET socket, ISocketEventDispatcher* dispatcher)
		:mDispatcher(dispatcher)
	{
		Init(socket);
	}

	Socket::~Socket() {
		if (Closed != mStatus) {
			::closesocket(mSocket);
		}

		/*string buf = "";
		bool has = true;
		while (has) {
			has = mPendingWrites.try_dequeue(buf);
		}*/
	}

	void Socket::Init(SOCKET socket) {
		using std::exception;

		if (INVALID_SOCKET == socket) {
			throw exception("Invalid socket");
		}

		mStatus = Normal;
		mSocket = socket;
		memset(&mPeer, 0, sizeof(mPeer));
	}

	bool Socket::IsConnected(unsigned long& time) {
		bool connected = false;
		if (INVALID_SOCKET == mSocket || Closed == mStatus) {
			connected = false;
		}
		else {
			int size = sizeof(time);
			int ret = getsockopt(mSocket, SOL_SOCKET, SO_CONNECT_TIME, reinterpret_cast<char*>(&time), &size);
			if (SOCKET_ERROR == ret) {
				connected = false;
			}
			else {
				connected = 0xFFFFFFFF != time;
			}
		}

		if (!connected) {
			time = 0l;
		}
		return connected;
	}

	void Socket::OnReadZeroByte(IOBuffer* buffer) {
		if (0 == ::InterlockedDecrement(&mPendingReads)) {
			Close();
		}
		delete buffer;
	}

	void Socket::Close() {
		if (FALSE == ::InterlockedCompareExchange(&mIsClosed, TRUE, FALSE)) {
			mDispatcher->TriggerPreClose(*this);
			::closesocket(mSocket);
			mStatus = Closed;
			DecreaseRef();
		}
	}

	/*void Socket::RegisterEventHandler(ISocketEventDispatcher& dispatcher) {
		dispatcher.Register(new Socket::SocketEventHandler());
	}*/

	void Socket::pushInReads(IOBuffer* buffer) {
		char* buffRecv = new char[buffer->GetUsed() + 1]{0};
		memcpy(buffRecv, buffer->GetPointer(0), buffer->GetUsed());
		buffRecv[buffer->GetUsed()] = '\0';
		mPendingReadQueue.enqueue(buffRecv);
		delete[] buffRecv;
	}

	bool Socket::Read(IOBuffer* buffer) {
		if (nullptr == buffer) {
			throw std::exception("The argument 'buffer' cannot be null.");
		}

		if (mStatus == Closed || mStatus == DenyReceive || mStatus == DenySendnReceive) {
			throw std::exception(mStatusDescription[mStatus]);
		}
		// check server status
		if (CSessionMgr::GetInstance()->isShutting()) {
			throw std::exception("server closed");
		}

		DWORD numberOfBytesRecvd;
		DWORD flag = 0;

		buffer->SetOperation(IO_Operation::IO_Read_Completed);
		mDispatcher->TriggerPreRead(*this, *buffer);
		WSABUF buf = {
			buffer->GetSize() - buffer->GetUsed(),
			(char*)buffer->GetPointer(buffer->GetUsed())
		};

		int ret = WSARecv(mSocket, &buf, 1, &numberOfBytesRecvd, &flag, static_cast<WSAOVERLAPPED*>(buffer), nullptr);
		int err = ERROR_SUCCESS;
		if (SOCKET_ERROR == ret && WSA_IO_PENDING != WSAGetLastError()) {
			err = WSAGetLastError();
		}
		return 0 == ret;
	}

	bool Socket::DoWrite(string& send) {
		if (mStatus == Closed || mStatus == DenySend || mStatus == DenySendnReceive) {
			//throw std::exception(mStatusDescription[mStatus]);
			mPendingWrites.enqueue(send);
			return false;
		}

		size_t sendsize = send.size();
		IOBuffer* sendBuf = new (sendsize) IOBuffer(sendsize, *this);
		//char base[1] = { '\x11' };
		//sendBuf->Append(base, 1);
		sendBuf->CopyFrom(0, send.c_str(), sendsize);
		//memcpy(sendBuf->GetPointer(1), send.c_str(), send.size());
		//size_t sendsize = send.size();
		//shared_ptr<IOBuffer> sendBuf = make_shared<IOBuffer>(sendsize, *this);
		//memcpy(sendBuf->GetPointer(), send.c_str(), sendsize);
		sendBuf->SetUsed(sendBuf->GetUsed() + sendsize);
		sendBuf->SetOperation(IO_Operation::IO_Write_Completed);
		mDispatcher->TriggerPreWrite(*this, *sendBuf);

		DWORD sentBytes;
		WSABUF buf = { sendBuf->GetUsed(), (char*)sendBuf->GetPointer() };

		int ret = WSASend(mSocket, &buf, 1, &sentBytes, 0, static_cast<WSAOVERLAPPED*>(sendBuf), NULL);
		if (SOCKET_ERROR == ret && WSA_IO_PENDING != WSAGetLastError()) {
			//throw std::exception("send error !");
			mPendingWrites.enqueue(send);
			return false;
		}
		
		return 0 == ret;
	}

	void Socket::Shutdown(int how) {
		if (DenyReceive != how && DenySend != how && DenySendnReceive != how) {
			throw std::exception("Undefine operation");
		}
		mStatus = static_cast<SocketStatus>(how);
		::shutdown(mSocket, how);
	}

	bool Socket::OnSend(string& data) {
		string sendItem = "";
		bool hasFind = mPendingWrites.try_dequeue(sendItem);
		if (hasFind) {
			//把新来的压进去
			mPendingWrites.enqueue(data);
		}
		else {
			sendItem = data;
		}
		return DoWrite(sendItem);
		/*shared_ptr<IOBuffer> send = make_shared<IOBuffer>(data.size(), *this);
		memcpy(send->GetPointer(), data.c_str(), data.size());
		send->SetUsed(data.size());
		Write(send);*/
	}

	void Socket::WriteNext() {
		string sendItem = "";
		bool hasFind = mPendingWrites.try_dequeue(sendItem);
		if (hasFind)
			DoWrite(sendItem);
	}

	//void Socket::Write(IOBuffer* buffer) {
	//	if (nullptr == buffer) {
	//		throw std::exception("The argument 'buffer' cannot be null.");
	//	}
	//	// check server status
	//	if (CSessionMgr::GetInstance()->isShutting()) {
	//		throw std::exception("server closed !");
	//	}

	//	IOBuffer* sendBuf = nullptr;
	//	bool hasFind = mPendingWrites.try_dequeue(sendBuf);
	//	if (hasFind && sendBuf) {
	//		DoWrite(sendBuf);
	//		mPendingWrites.enqueue(buffer);
	//	}
	//	else {
	//		DoWrite(buffer);
	//	}
	//}

	//void Socket::Write(const vector<IOBuffer *>& buffers) {
	//	if (buffers.empty()) {
	//		throw std::exception("The argument 'buffers' cannot be empty.");
	//	}

	//	// check server status
	//	if (CSessionMgr::GetInstance()->isShutting()) {
	//		throw std::exception("server closed !");
	//	}

	//	IOBuffer* buffer = nullptr;
	//	bool hasFind = mPendingWrites.try_dequeue(buffer);
	//	auto first = buffers.begin();

	//	if (hasFind) {
	//		DoWrite(buffer);
	//	}
	//	else {
	//		DoWrite(first);
	//		++first;
	//	}

	//	while (first != buffers.end()) {
	//		mPendingWrites.enqueue()
	//		++first;
	//	}
	//}

	bool Socket::OnRecv(string& data) {
		return mPendingReadQueue.try_dequeue(data);
	}

	//void Socket::SocketEventHandler::PostWrite(Socket& socket, IOBuffer& buffer) {
	//	if (!socket.mServer.IsShutting() && !socket.mPendingWrites.IsEmpty()) {
	//		socket.DoWrite(socket.mPendingWrites.Dequeue());
	//	}
	//}

	//void Socket::SocketEventHandler::PostRead(Socket& socket, IOBuffer& buffer) {
	//	::InterlockedDecrement(&socket.mPendingReads);
	//	//printf("SocketEventHandler:PostRead %d \n", ::GetCurrentThreadId());
	//	//socket.Write(&buffer);
	//}

	//void Socket::SocketEventHandler::PreRead(Socket& socket, IOBuffer& buffer) {
	//	::InterlockedIncrement(&socket.mPendingReads);
	//	::InterlockedIncrement(&Statistics::PendingReads);
	//}

	//void Socket::SocketEventHandler::PreWrite(Socket& socket, IOBuffer& buffer) {
	//	::InterlockedIncrement(&Statistics::PendingWrites);
	//}
}