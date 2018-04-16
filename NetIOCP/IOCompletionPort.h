#pragma once

#include <Windows.h>

namespace NetIOCP {
	/*
	该类为IOCP操作的封装类
	*/
	class IOCompletionPort {
	public:
		IOCompletionPort(const IOCompletionPort&) = delete;
		IOCompletionPort& operator=(const IOCompletionPort&) = delete;
	public:
		//用explicit关键字保证必须调用该构造函数
		explicit IOCompletionPort(DWORD nConcurrentThreads = 0);
		~IOCompletionPort() {
			::CloseHandle(mHIocp);
		}
		//为完成端口绑定socket（完成端口在构造函数创建）
		template<typename TCompletionKey>
		bool GetSociateSocket(SOCKET socket, TCompletionKey completionKey) {
			static_assert(sizeof(completionKey) == sizeof(ULONG_PTR),
				"Can not convert completionKey to type ULONG_PTR");

			return mHIocp ==
				::CreateIoCompletionPort(
					reinterpret_cast<HANDLE>(socket),
					mHIocp,
					(ULONG_PTR)completionKey,
					0
				);
		}

		//让工作器线程在完成端口等待
		template<typename TCompletionKey, typename TOverlapped>
		bool GetQueuedCompletionStatus(
			LPDWORD lpNumberOfBytes,
			TCompletionKey *lpCompletionKey,
			TOverlapped **lpOverlapped,
			DWORD dwMilliseconds
		) {
			static_assert(sizeof(lpCompletionKey) == sizeof(PULONG_PTR),
				"Can not convert lpCompletionKey to type PULONG_PTR");

			static_assert(sizeof(lpOverlapped) == sizeof(LPOVERLAPPED),
				"Can not convert lpOverlapped to type LPOVERLAPPED");

			return TRUE == ::GetQueuedCompletionStatus(
				mHIocp,
				lpNumberOfBytes,
				reinterpret_cast<PULONG_PTR>(lpCompletionKey),
				reinterpret_cast<LPOVERLAPPED*>(lpOverlapped),
				dwMilliseconds
			);
		}
		//发送结束消息 用于系统退出
		template<typename TCompletionKey, typename TOverlapped>
		bool PostQueuedCompletionStatus(
			DWORD numberOfBytes,
			TCompletionKey completionKey,
			TOverlapped *lpOverlapped
		) {
			static_assert(sizeof(completionKey) == sizeof(PULONG_PTR),
				"Can not convert lpCompletionKey to type PULONG_PTR");

			static_assert(sizeof(lpOverlapped) == sizeof(LPOVERLAPPED),
				"Can not convert lpOverlapped to type LPOVERLAPPED");

			return TRUE == ::PostQueuedCompletionStatus(
				mHIocp,
				numberOfBytes,
				(ULONG_PTR)(completionKey),
				static_cast<LPOVERLAPPED>(lpOverlapped)
			);
		}
	private:
		HANDLE mHIocp;  //完成端口句柄
	};
}