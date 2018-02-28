#include "stdafx.h"

namespace NetIOCP {
	Socket* TcpSocketFactory::Create(ISocketEventDispatcher* dispatcher) {
		SOCKET sTcp = WSAUtility::CreateOverlappedSocket(WSAUtility::TCP());
		return new Socket(sTcp, dispatcher);
	}
}