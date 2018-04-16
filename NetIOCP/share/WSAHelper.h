#pragma once

#include <WinSock2.h>
#include <IPHlpApi.h>
#include <MSWSock.h>

namespace NetIOCP {
	/*
	WinSock�ӿڷ�װ
	*/
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
	/*
	WinSock��ʼ��
	*/
	class WSAInitializor {
	public:
		WSAInitializor();
		~WSAInitializor();
	private:
		int err{ 0 };
	};

	/*
	�������ռ�ר�����ڴ���socket
	*/
	namespace WSAUtility {
		/*
		struct TCP {};
		struct UDP {};

		template<typename TProtocol>
		SOCKET CreateOverlappedSocket(TProtocol);

		template<>
		SOCKET CreateOverlappedSocket<TCP>(TCP);
		template<>
		SOCKET CreateOverlappedSocket<UDP>(UDP);
		*/
		SOCKET CreateOverlappedSocket(int type = IPPROTO_TCP);

		//���ｫwindows GetLastError()���صĴ�����ת��Ϊ�ַ�����Ϣ
		DWORD FormatMessageToString(LPTSTR *ppBuffer, DWORD dwErrCode);
		DWORD FormatMessageToStringA(LPSTR *ppBuffer, DWORD dwErrCode);
		DWORD FormatMessageToStringW(LPWSTR *ppBuffer, DWORD dwErrCode);
	}
}