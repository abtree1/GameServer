#include "stdafx.h"

namespace NetIOCP {
	void TcpSocketEventHandler::ServerEventHandler::PreShutdown() {

	}

	void TcpSocketEventHandler::ServerEventHandler::PostShutdown() {
		for (auto &it : mEventHandler.mSocketSet) {
			it.second->Close();
		}
		mEventHandler.mSocketSet.clear();
	}

	void TcpSocketEventHandler::PostAccept(Socket& socket, IOBuffer& buffer) {
		cout << " Socket accepted: " << socket.AsSocket() << endl;
		CSessionMgr::GetInstance()->registerNewConn(&socket);
		IOBuffer* readBuf = new (BUFFER_SIZE) IOBuffer(BUFFER_SIZE, socket);
		socket.Read(readBuf);
	}

	void TcpSocketEventHandler::PostRead(Socket& socket, IOBuffer& buffer) {
		printf("TcpSocketEventHandler:PostRead %d \n", ::GetCurrentThreadId());
		socket.pushInReads(&buffer);
		IOBuffer* readBuf = new (BUFFER_SIZE) IOBuffer(BUFFER_SIZE, socket);
		socket.Read(readBuf);
	}

	void TcpSocketEventHandler::PostClose(Socket& socket) {
		cout << " Socket closed: " << socket.AsSocket() << endl;
		if (!CSessionMgr::GetInstance()->isShutting()) {
			mSocketSet.erase(socket.AsSocket());
		}
	}

	void TcpSocketEventHandler::PostWrite(Socket& socket, IOBuffer& buffer) {
		delete &buffer;
		socket.WriteNext();
	}

	void TcpSocketEventHandler::PreAccept(Socket& socket, IOBuffer& buffer) {
		cout << "Waiting for connection request" << endl;
	}
}