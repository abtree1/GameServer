#include "stdafx.h";

namespace NetIOCP {
	TcpConnectionManager::TcpConnectionManager(ISocketEventDispatcher* dsp)
		:mDispatcher(dsp) {
		mFactory = new TcpSocketFactory();
		//这里注册一个event 专门用于处理socket的连接的建立和关闭
		dsp->Register(new TcpConnectionManager::SocketEventHandler(this));
	}

	void TcpConnectionManager::OnDisconnected(Socket* socket, IOBuffer* buffer) {
		buffer->Clear();
		PostAcceptRequest(socket, buffer);
	}

	void TcpConnectionManager::Process() {
		PostAcceptRequest();
	}

	bool TcpConnectionManager::PostAcceptRequest() {
		//预先为客户端创建一个socket
		Socket* s = mFactory->Create(mDispatcher);
		IOBuffer* buf = new (BUFFER_SIZE)IOBuffer(BUFFER_SIZE, *s);
		//用这个socket开始等待客户端连入
		return PostAcceptRequest(s, buf);
	}

	bool TcpConnectionManager::PostAcceptRequest(Socket* socket, IOBuffer* buffer) {
		DWORD bytes = 0;
		BOOL isCompleted = FALSE;
		buffer->SetOperation(IO_Operation::IO_Accept_Completed);

		do {
			mDispatcher->TriggerPreAccept(*socket, *buffer);
			isCompleted = WSAExtMethods::AcceptEx(
				CSessionMgr::GetInstance()->ServerSocket(),
				socket->GetSocket(),
				buffer->GetPointer(),
				buffer->GetSize() - ((sizeof(sockaddr_in) + 16) * 2),
				sizeof(sockaddr_in) + 16,
				sizeof(sockaddr_in) + 16,
				&bytes,
				static_cast<LPOVERLAPPED>(buffer)
			);
			if (isCompleted) {
				CSessionMgr::GetInstance()->GetIOCompletionPort().PostQueuedCompletionStatus(bytes, socket, buffer);
				break;
			}
			else {
				if (WSAECONNRESET == WSAGetLastError()) {
					continue;
				}
				else if (WSA_IO_PENDING == WSAGetLastError()) {
					break;
				}
				else {
					// TODO: write log
					int err = WSAGetLastError();
					//socket->DecreaseRef();
					delete buffer;
				}
			}
		} while (true);
		return isCompleted == TRUE;
	}

	void TcpConnectionManager::SocketEventHandler::PostAccept(Socket& socket, IOBuffer& buffer) {
		::InterlockedIncrement(&Statistics::ConnectingSockets);
		mMonitor->PostAcceptRequest();
	}

	void TcpConnectionManager::SocketEventHandler::PreAccept(Socket& socket, IOBuffer& buffer) {

	}

	void TcpConnectionManager::SocketEventHandler::PostClose(Socket& socket) {
		::InterlockedDecrement(&Statistics::ConnectingSockets);
	}
}