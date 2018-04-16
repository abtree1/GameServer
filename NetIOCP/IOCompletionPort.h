#pragma once

#include <Windows.h>

namespace NetIOCP {
	/*
	����ΪIOCP�����ķ�װ��
	*/
	class IOCompletionPort {
	public:
		IOCompletionPort(const IOCompletionPort&) = delete;
		IOCompletionPort& operator=(const IOCompletionPort&) = delete;
	public:
		//��explicit�ؼ��ֱ�֤������øù��캯��
		explicit IOCompletionPort(DWORD nConcurrentThreads = 0);
		~IOCompletionPort() {
			::CloseHandle(mHIocp);
		}
		//Ϊ��ɶ˿ڰ�socket����ɶ˿��ڹ��캯��������
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

		//�ù������߳�����ɶ˿ڵȴ�
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
		//���ͽ�����Ϣ ����ϵͳ�˳�
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
		HANDLE mHIocp;  //��ɶ˿ھ��
	};
}