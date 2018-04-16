#include "stdafx.h"

namespace NetIOCP {
	LPFN_ACCEPTEX WSAExtMethods::AcceptEx = NULL;
	LPFN_GETACCEPTEXSOCKADDRS WSAExtMethods::GetAcceptExSockaddrs = NULL;
	LPFN_CONNECTEX WSAExtMethods::ConnectEx = NULL;
	LPFN_DISCONNECTEX WSAExtMethods::DisconnectEx = NULL;
	LPFN_TRANSMITFILE WSAExtMethods::TransmitFile = NULL;
	LPFN_TRANSMITPACKETS WSAExtMethods::TransmitPackets = NULL;
	LPFN_WSARECVMSG WSAExtMethods::WSARecvMsg = NULL;
	LPFN_WSASENDMSG WSAExtMethods::WSASendMsg = NULL;
	bool WSAExtMethods::isInit = false;

	WSAExtMethods::WSAExtMethods() {
		if (isInit)
			return;
		isInit = true;

		SOCKET temp = ::WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);

		//这里为socket需要设置的参数
		GUID guidAcceptEx = WSAID_ACCEPTEX,
			guidGetAcceptExSockaddrs = WSAID_GETACCEPTEXSOCKADDRS,
			guidConnectEx = WSAID_CONNECTEX,
			guidDisconnectEx = WSAID_DISCONNECTEX,
			guidTransmitFile = WSAID_TRANSMITFILE,
			guidTransmitPackets = WSAID_TRANSMITPACKETS,
			guidWSARecvMsg = WSAID_WSARECVMSG,
			guidWSASendMsg = WSAID_WSASENDMSG;

		//以下为socket设置的具体参数
		DWORD dwBytes;
		WSAIoctl(
			temp,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidAcceptEx,
			sizeof(guidAcceptEx),
			&WSAExtMethods::AcceptEx,
			sizeof(WSAExtMethods::AcceptEx),
			&dwBytes,
			NULL,
			NULL
		);

		WSAIoctl(
			temp,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidGetAcceptExSockaddrs,
			sizeof(guidGetAcceptExSockaddrs),
			&WSAExtMethods::GetAcceptExSockaddrs,
			sizeof(WSAExtMethods::GetAcceptExSockaddrs),
			&dwBytes,
			NULL,
			NULL
		);

		WSAIoctl(
			temp,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidConnectEx,
			sizeof(guidConnectEx),
			&WSAExtMethods::ConnectEx,
			sizeof(WSAExtMethods::ConnectEx),
			&dwBytes,
			NULL,
			NULL
		);

		WSAIoctl(
			temp,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidDisconnectEx,
			sizeof(guidDisconnectEx),
			&WSAExtMethods::DisconnectEx,
			sizeof(WSAExtMethods::DisconnectEx),
			&dwBytes,
			NULL,
			NULL
		);

		WSAIoctl(
			temp,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidTransmitFile,
			sizeof(guidTransmitFile),
			&WSAExtMethods::TransmitFile,
			sizeof(WSAExtMethods::TransmitFile),
			&dwBytes,
			NULL,
			NULL
		);


		WSAIoctl(
			temp,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidTransmitPackets,
			sizeof(guidTransmitPackets),
			&WSAExtMethods::TransmitPackets,
			sizeof(WSAExtMethods::TransmitPackets),
			&dwBytes,
			NULL,
			NULL
		);


		WSAIoctl(
			temp,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidWSARecvMsg,
			sizeof(guidWSARecvMsg),
			&WSAExtMethods::WSARecvMsg,
			sizeof(WSAExtMethods::WSARecvMsg),
			&dwBytes,
			NULL,
			NULL
		);


		WSAIoctl(
			temp,
			SIO_GET_EXTENSION_FUNCTION_POINTER,
			&guidWSASendMsg,
			sizeof(guidWSASendMsg),
			&WSAExtMethods::WSASendMsg,
			sizeof(WSAExtMethods::WSASendMsg),
			&dwBytes,
			NULL,
			NULL
		);

		::closesocket(temp);
	}

	WSAInitializor::WSAInitializor() {
		//winsock初始化
		WORD wVersion = MAKEWORD(2, 2);
		WSADATA wsData;
		this->err = WSAStartup(wVersion, &wsData);
		if (this->err) {
			//错误处理
			//throw _T("wsa init failed.");
		}

		WSAExtMethods em;
	}

	WSAInitializor::~WSAInitializor() {
		if (!this->err) {
			WSACleanup();
		}
	}

	namespace WSAUtility {
		/*
		template<typename TProtocol>
		SOCKET CreateOverlappedSocket(TProtocol) {
			//不能创建非TCP和UDP的socket
			throw std::exception();
		};

		template<>
		SOCKET CreateOverlappedSocket<TCP>(TCP) {
			//创建TCP的带重叠IO标识的socket
			return ::WSASocket(AF_INET,
				SOCK_STREAM,
				IPPROTO_TCP,
				NULL, 0,
				WSA_FLAG_OVERLAPPED);
		};

		template<>
		SOCKET CreateOverlappedSocket<UDP>(UDP) {
			//创建UDP的带重叠IO标识的socket
			return ::WSASocket(AF_INET,
				SOCK_DGRAM,
				IPPROTO_UDP,
				NULL, 0,
				WSA_FLAG_OVERLAPPED);
		};
		*/
		SOCKET CreateOverlappedSocket(int type) {
			if (type == IPPROTO_TCP) {
				//创建带重叠IO标识的socket
				return ::WSASocket(AF_INET,
					SOCK_STREAM,
					IPPROTO_TCP,
					NULL, 0,
					WSA_FLAG_OVERLAPPED);
			}
			else if (type == IPPROTO_UDP) {
				//创建UDP的带重叠IO标识的socket
				return ::WSASocket(AF_INET,
					SOCK_DGRAM,
					IPPROTO_UDP,
					NULL, 0,
					WSA_FLAG_OVERLAPPED);
			}
			else {
				throw std::exception();
			}
			//只能创建TCP和UDP的Socket
			//if(type != IPPROTO_TCP && type != IPPROTO_UDP)
			//	throw std::exception();
			////创建带重叠IO标识的socket
			//return ::WSASocket(AF_INET,
			//	SOCK_DGRAM,
			//	type,
			//	NULL, 0,
			//	WSA_FLAG_OVERLAPPED);
		};
		DWORD FormatMessageToString(LPTSTR *ppBuffer, DWORD dwErrCode) {
			return FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
				FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, dwErrCode,
				//MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),// Default language
				MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
				(LPTSTR)ppBuffer, 0, NULL
			);
		}

		DWORD FormatMessageToStringA(LPSTR *ppBuffer, DWORD dwErrCode) {
			return FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER |
				FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, dwErrCode,
				//MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),// Default language
				MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
				(LPSTR)ppBuffer, 0, NULL
			);
		}

		DWORD FormatMessageToStringW(LPWSTR *ppBuffer, DWORD dwErrCode) {
			return FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
				FORMAT_MESSAGE_FROM_SYSTEM |
				FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, dwErrCode,
				//MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),// Default language
				MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
				(LPWSTR)ppBuffer, 0, NULL
			);
		}
	}
}