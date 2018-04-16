#include "stdafx.h";

namespace NetIOCP {
	TcpConnectionManager::TcpConnectionManager(ISocketEventDispatcher* dsp)
		:mDispatcher(dsp) {
		mFactory = new TcpSocketFactory();
		//����ע��һ��event ר�����ڴ���socket�����ӵĽ����͹ر�
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
		//Ԥ��Ϊ�ͻ��˴���һ��socket
		Socket* s = mFactory->Create(mDispatcher);
		IOBuffer* buf = new (BUFFER_SIZE)IOBuffer(BUFFER_SIZE, *s);
		//�����socket��ʼ�ȴ��ͻ�������
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