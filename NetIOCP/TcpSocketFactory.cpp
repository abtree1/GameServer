#include "stdafx.h"

namespace NetIOCP {
	Socket* TcpSocketFactory::Create(ISocketEventDispatcher* dispatcher) {
		//SOCKET sTcp = WSAUtility::CreateOverlappedSocket(WSAUtility::TCP());
		//创建一个带重叠io的socket句柄
		SOCKET sTcp = WSAUtility::CreateOverlappedSocket();
		//创建Socket对象
		return new Socket(sTcp, dispatcher);
	}
}