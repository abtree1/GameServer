#pragma once

#include <WinSock2.h>
#include <IPHlpApi.h>
#include <MSWSock.h>

namespace NetIOCP {
	class WSAExtMethods {
	public:
		WSAExtMethods();
	private:
		static bool isInit;
	public:
		static LPFN_ACCEPTEX AcceptEx;
		static LPFN_GETACCEPTEXSOCKADDRS GetAcceptExSockaddrs;
		static LPFN_CONNECTEX ConnectEx;
		static LPFN_DISCONNECTEX DisconnectEx;
		static LPFN_TRANSMITFILE TransmitFile;
		static LPFN_TRANSMITPACKETS TransmitPackets;
		static LPFN_WSARECVMSG WSARecvMsg;
		static LPFN_WSASENDMSG WSASendMsg;
	};

	class WSAInitializor {
	public:
		WSAInitializor();
		~WSAInitializor();
	private:
		int err{ 0 };
	};

	namespace WSAUtility {
		struct TCP {};
		struct UDP {};

		template<typename TProtocol>
		SOCKET CreateOverlappedSocket(TProtocol);

		template<>
		SOCKET CreateOverlappedSocket<TCP>(TCP);
		template<>
		SOCKET CreateOverlappedSocket<UDP>(UDP);

		//这里将windows GetLastError()返回的错误码转化为字符串信息
		DWORD FormatMessageToString(LPTSTR *ppBuffer, DWORD dwErrCode);
		DWORD FormatMessageToStringA(LPSTR *ppBuffer, DWORD dwErrCode);
		DWORD FormatMessageToStringW(LPWSTR *ppBuffer, DWORD dwErrCode);
	}
}