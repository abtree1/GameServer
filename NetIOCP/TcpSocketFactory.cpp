#include "stdafx.h"

namespace NetIOCP {
	Socket* TcpSocketFactory::Create(ISocketEventDispatcher* dispatcher) {
		//SOCKET sTcp = WSAUtility::CreateOverlappedSocket(WSAUtility::TCP());
		//����һ�����ص�io��socket���
		SOCKET sTcp = WSAUtility::CreateOverlappedSocket();
		//����Socket����
		return new Socket(sTcp, dispatcher);
	}
}