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
		//if (0 == ::InterlockedDecrement(&mPendingReads)) {
		Close();
		//}
		delete buffer;
	}

	void Socket::Close() {
		if (FALSE == ::InterlockedCompareExchange(&mIsClosed, TRUE, FALSE)) {
			mDispatcher->TriggerPreClose(*this);
			::closesocket(mSocket);
			mStatus = Closed;
			//DecreaseRef();
			mDispatcher->TriggerPostClose(*this);
		}
	}

	/*void Socket::RegisterEventHandler(ISocketEventDispatcher& dispatcher) {
		dispatcher.Register(new Socket::SocketEventHandler());
	}*/

	void Socket::pushInReads(IOBuffer* buffer) {
		//注意 底层并不会去验证数据的正确性 需要上层验证
		if (mMaxSize == 0) { //表示收到一个新消息
			if (buffer->GetUsed() < INT_SIZE)
				return;  //新消息必须大于这个值
			char* buffSize = new char[INT_SIZE]{ 0 };
			memcpy(buffSize, buffer->GetPointer(), INT_SIZE);
			mMaxSize = *buffSize;
			//表示还有其它数据
			if (buffer->GetUsed() > INT_SIZE) {
				//读取剩余数据
				char* buffRecv = new char[buffer->GetUsed() - INT_SIZE + 1]{ 0 };
				memcpy(buffRecv, buffer->GetPointer(INT_SIZE), buffer->GetUsed());
				buffRecv[buffer->GetUsed() - INT_SIZE] = '\0';
				//加入到缓存
				mCliDataTemp += buffRecv;
				delete[] buffRecv;
				//设置当前的数据进度
				mCurSize += buffer->GetUsed() - INT_SIZE;
			}
		}
		else {//表示上一个消息的补充部分
			//读取整个数据包
			char* buffRecv = new char[buffer->GetUsed() + 1]{ 0 };
			memcpy(buffRecv, buffer->GetPointer(), buffer->GetUsed());
			buffRecv[buffer->GetUsed()] = '\0';
			//加入到缓存
			mCliDataTemp += buffRecv;
			//mPendingReadQueue.enqueue(buffRecv);
			delete[] buffRecv;
			//更新进度
			mCurSize += buffer->GetUsed();
		}
		//此处表示已经完整接收了这个消息
		if (mCurSize >= mMaxSize) {
			//加进消息队列
			mPendingReadQueue.enqueue(mCliDataTemp);
			//还原数据
			mCliDataTemp = "";
			mMaxSize = mCurSize = 0;
		}
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
		//检查状态
		if (mStatus == Closed || mStatus == DenySend || mStatus == DenySendnReceive) {
			//throw std::exception(mStatusDescription[mStatus]);
			mPendingWrites.enqueue(send);
			return false;
		}

		int sendsize = send.size();
		IOBuffer* sendBuf = new (sendsize + INT_SIZE) IOBuffer(sendsize + INT_SIZE, *this);
		sendBuf->CopyFrom(0, &sendsize, INT_SIZE);  //先将长度加进去
		sendBuf->CopyFrom(INT_SIZE, send.c_str(), sendsize); //在将内容加进去
		sendBuf->SetUsed(INT_SIZE + sendsize); 
		sendBuf->SetOperation(IO_Operation::IO_Write_Completed);
		mDispatcher->TriggerPreWrite(*this, *sendBuf);

		DWORD sentBytes;
		WSABUF buf = { sendBuf->GetUsed(), (char*)sendBuf->GetPointer() };
		//发送数据
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

	bool Socket::Disconnect() {
		IOBuffer* buf = new (BUFFER_SIZE)IOBuffer(BUFFER_SIZE, *this);
		buf->SetOperation(IO_Operation::IO_Termination);
		//这里退出后socket留待复用
		int ret = WSAExtMethods::DisconnectEx(mSocket, buf, TF_REUSE_SOCKET, 0);
		if (TRUE == ret) {
			CSessionMgr::GetInstance()->GetMonitor()->OnDisconnected(this, buf);
			return true;
		}
		else {
			delete buf; //先删除重叠对象
			if (WSA_IO_PENDING == WSAGetLastError()) {
				//此时需要等待完成 但可以算断开成功
				return true;
			}
		}
		//表示失败
		return false;
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