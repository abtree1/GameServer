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

	Socket* TcpConnectionManager::Connect(string ip, int port) {
		//先创建一个socket
		Socket* cli = mFactory->Create(mDispatcher);
		if (!cli)
			return nullptr;
		//创建连接地址
		SOCKADDR_IN internetAddr;
		internetAddr.sin_family = AF_INET;		//几乎固定值（表示ip协议类型）		
		internetAddr.sin_addr.s_addr = inet_addr(ip.c_str());//将点分地址转换为4字节整数，分配给sin_addr
		internetAddr.sin_port = htons(port);//将port从主机存储顺序转换为网络存储顺序(htons)
		cli->SetPeerAddress(internetAddr);
		//需要先绑定一下(这是ConnectEx的内在需求)
		SOCKADDR_IN localaddr;
		localaddr.sin_family = AF_INET;
		localaddr.sin_addr.S_un.S_addr = INADDR_ANY;
		localaddr.sin_port = 0;
		if(SOCKET_ERROR == ::bind(cli->GetSocket(), (LPSOCKADDR)&localaddr, sizeof(localaddr))){
			printf("bind client socket error! \r\n");
			closesocket(cli->GetSocket());
			delete cli;
			return nullptr;
		}
		//创建一个buffer
		IOBuffer* buf = new (BUFFER_SIZE)IOBuffer(BUFFER_SIZE, *cli);
		string sendbit = "1234567890";
		buf->Append(sendbit.c_str(), sendbit.size());
		//开始连接服务器
		DWORD dwSend = 0;
		if (FALSE == WSAExtMethods::ConnectEx(
			cli->GetSocket(),
			(const sockaddr*)&internetAddr, sizeof(internetAddr),
			buf->GetPointer(), buf->GetUsed(),
			&dwSend,
			static_cast<LPOVERLAPPED>(buf)
		)) {
			auto errorcode = WSAGetLastError();
			//如果不是连接未完成 需要等待
			if (WSA_IO_PENDING != errorcode) {
				//如果发生错误 ...
				printf("client connect failed! ErrorCode:%d \n", errorcode);
				closesocket(cli->GetSocket());
				delete cli;
				return nullptr;
			}
		}
		//等待反馈连接结果
		DWORD dwFlag = 0, dwTrans = 0;
		if (!WSAGetOverlappedResult(cli->GetSocket(), static_cast<LPOVERLAPPED>(buf), &dwTrans, TRUE, &dwFlag))
		{
			printf("wait connect to server failed! \r\n");
			closesocket(cli->GetSocket());
			delete cli;
			return nullptr;
		}
		return cli;
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