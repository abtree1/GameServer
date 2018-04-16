#include "stdafx.h"

namespace NetIOCP {
	TcpSocketEventDispatcher::~TcpSocketEventDispatcher() {
		auto first = mHandlers.begin();
		for (auto &it : mHandlers) {
			delete it;
		}
	}

	void TcpSocketEventDispatcher::UpdateSocket(Socket& skt, IOBuffer& buffer) {
		SOCKET sServer = CSessionMgr::GetInstance()->ServerSocket();
		int ret = setsockopt(skt.GetSocket(), SOL_SOCKET, SO_UPDATE_ACCEPT_CONTEXT, (char*)&sServer, sizeof(sServer));
		if (SOCKET_ERROR == ret) {
			throw std::exception("update socket error!");
		}

		SOCKADDR *lpLocalSockaddr = nullptr, *lpRemoteSockaddr = nullptr;
		int LocalSockaddrLen = 0, RemoteSockaddrLen = 0;

		WSAExtMethods::GetAcceptExSockaddrs(
			buffer.GetPointer(),
			buffer.GetSize() - ((sizeof(sockaddr_in) + 16) * 2),
			sizeof(SOCKADDR_IN) + 16,
			sizeof(SOCKADDR_IN) + 16,
			&lpLocalSockaddr,
			&LocalSockaddrLen,
			&lpRemoteSockaddr,
			&RemoteSockaddrLen
		);
		memcpy(skt.GetPeerAddress(), lpRemoteSockaddr, RemoteSockaddrLen);
	}

	void TcpSocketEventDispatcher::Process() {
		IOCompletionPort& iocp = CSessionMgr::GetInstance()->GetIOCompletionPort();
		IConnectionManager* monitor = CSessionMgr::GetInstance()->GetMonitor();
		DWORD numberOfBytes = 0;
		Socket* socket = nullptr;
		IOBuffer* buffer = nullptr;
		mbRunning = true;

		while (true) {
			//开始等待返回
			bool isSuccess = CSessionMgr::GetInstance()->GetIOCompletionPort().GetQueuedCompletionStatus(&numberOfBytes, &socket, &buffer, INFINITE);
			//发生错误
			if (!isSuccess) {
				// TODO: write log
				DWORD err = ::GetLastError();
				if (ERROR_NETNAME_DELETED == err) {
					::InterlockedDecrement(&Statistics::PendingReads);
					socket->OnReadZeroByte(buffer);
					continue;
				}
				break;
			}
			//已经关闭(用于系统关闭)
			if (buffer->GetOperation() == IO_Operation::IO_Termination) {
				break;
			}

			switch (buffer->GetOperation()) {
			case IO_Operation::IO_Accept_Completed:
			{
				if (CSessionMgr::GetInstance()->isShutting()) {
					//socket->DecreaseRef();
					delete buffer;
					break;
				}
				socket = &buffer->GetSocket();
				iocp.GetSociateSocket(socket->GetSocket(), socket);

				if (0 == numberOfBytes) {
					buffer->SetOperation(IO_Operation::IO_Disconnect_Completed);
					int ret = WSAExtMethods::DisconnectEx(socket->GetSocket(), buffer, TF_REUSE_SOCKET, 0);
					if (TRUE == ret) {
						monitor->OnDisconnected(socket, buffer);
					}
					else {
						if (WSA_IO_PENDING != WSAGetLastError()) {
							// TODO: write log
							//socket->DecreaseRef();
							delete buffer;
						}
					}
				}
				else {
					UpdateSocket(*socket, *buffer);
					buffer->SetUsed(numberOfBytes + buffer->GetUsed());
					TriggerPostAccept(*socket, *buffer);
				}
			}
			break;
			case IO_Operation::IO_Disconnect_Completed:
			{
				monitor->OnDisconnected(socket, buffer);
			}
			break;
			case IO_Operation::IO_Read_Completed:
			{
				::InterlockedDecrement(&Statistics::PendingReads);
				//这里其实表示客户端已经断开了socket
				if (0 == numberOfBytes) { 
					socket->OnReadZeroByte(buffer);
				}
				else {
					//buffer->Seek(buffer->Seek() + 1);
					buffer->SetUsed(numberOfBytes + buffer->GetUsed());
#ifdef _DEBUG
					char* buffRecv = new char[numberOfBytes];
					memcpy(buffRecv, buffer->GetPointer(), buffer->GetUsed());
					buffRecv[numberOfBytes - 1] = '\0';
					printf("TcpSocketEventDispatcher recv data: %s \n", buffRecv);
					delete[] buffRecv;
#endif
					//socket->Write(buffer);
					TriggerPostRead(*socket, *buffer);
				}
			}
			break;
			case IO_Operation::IO_Write_Completed:
			{
				::InterlockedDecrement(&Statistics::PendingWrites);
				TriggerPostWrite(*socket, *buffer);
			}
			break;
			default:
			{
				// TODO: write log
				//if (nullptr != socket)
				//	socket->DecreaseRef();
				delete buffer;
			}
			break;
			}// end of switch

			numberOfBytes = 0;
			socket = nullptr;
			buffer = nullptr;
		}// end of while

		::InterlockedDecrement(&Statistics::AliveTask);
		if (!CSessionMgr::GetInstance()->isShutting()) {
			//TODO: write log
		}
	}

	void TcpSocketEventDispatcher::Register(ISocketEvent* handler) {
		if (mbRunning) {
			throw std::exception("Do not call Register(...) when the server is running.");
		}

		if (nullptr == handler) {
			throw std::exception("The argument 'handler' can not be null");
		}

		mHandlers.push_back(handler);
	}

	void TcpSocketEventDispatcher::TriggerPreAccept(Socket& socket, IOBuffer& buffer) {
		for (auto &it : mHandlers) {
			try {
				it->PreAccept(socket, buffer);
			}
			catch (...) {
				// TODO: write log
			}
		}
	}

	void TcpSocketEventDispatcher::TriggerPostAccept(Socket& socket, IOBuffer& buffer) {
		for (auto &it : mHandlers) {
			try {
				it->PostAccept(socket, buffer);
			}
			catch (...) {
				// TODO: write log
			}
		}
	}

	void TcpSocketEventDispatcher::TriggerError(Socket& socket) {
		for (auto &it : mHandlers) {
			it->OnError(socket);
		}
	}

	void TcpSocketEventDispatcher::TriggerPostClose(Socket& socket) {
		for (auto &it : mHandlers) {
			it->PostClose(socket);
		}
	}

	void TcpSocketEventDispatcher::TriggerPostRead(Socket& socket, IOBuffer& buffer) {
		for (auto &it : mHandlers) {
			it->PostRead(socket, buffer);
		}
	}

	void TcpSocketEventDispatcher::TriggerPostWrite(Socket& socket, IOBuffer& buffer) {
		for (auto &it : mHandlers) {
			it->PostWrite(socket, buffer);
		}
	}

	void TcpSocketEventDispatcher::TriggerPreClose(Socket& socket) {
		for (auto &it : mHandlers) {
			it->PreClose(socket);
		}
	}

	void TcpSocketEventDispatcher::TriggerPreRead(Socket& socket, IOBuffer& buffer) {
		for (auto &it : mHandlers) {
			it->PreRead(socket, buffer);
		}
	}

	void TcpSocketEventDispatcher::TriggerPreWrite(Socket& socket, IOBuffer& buffer) {
		for (auto &it : mHandlers) {
			it->PreWrite(socket, buffer);
		}
	}
}