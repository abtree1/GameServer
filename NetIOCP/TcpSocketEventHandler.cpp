#include "stdafx.h"

namespace NetIOCP {
	void TcpSocketEventHandler::ServerEventHandler::PreShutdown() {

	}

	void TcpSocketEventHandler::ServerEventHandler::PostShutdown() {
		/*for (auto &it : mEventHandler.mSocketSet) {
			it.second->Close();
		}
		mEventHandler.mSocketSet.clear();*/
	}

	void TcpSocketEventHandler::PreAccept(Socket& socket, IOBuffer& buffer) {
		cout << "Waiting for connection request" << endl;
	}

	void TcpSocketEventHandler::PostAccept(Socket& socket, IOBuffer& buffer) {
		cout << " Socket accepted: " << socket.GetSocket() << endl;
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

	void TcpSocketEventHandler::PreClose(Socket& socket) {
		cout << " Socket pre closed: " << socket.GetSocket() << endl;
		CSessionMgr::GetInstance()->CloseConn(&socket);
	}

	void TcpSocketEventHandler::PostClose(Socket& socket) {
		cout << " Socket closed: " << socket.GetSocket() << endl;
		/*if (!CSessionMgr::GetInstance()->isShutting()) {
			mSocketSet.erase(socket.GetSocket());
		}*/
	}

	void TcpSocketEventHandler::PostWrite(Socket& socket, IOBuffer& buffer) {
		delete &buffer;
		socket.WriteNext();
	}
}