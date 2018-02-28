#include "stdafx.h"

namespace NetIOCP {
	IOCompletionPort::IOCompletionPort(DWORD nConcurrentThreads /* = 0 */) {
		using std::exception;

		mHIocp = CreateIoCompletionPort(
			INVALID_HANDLE_VALUE,
			NULL,
			NULL,
			nConcurrentThreads
		);

		if (NULL == mHIocp) {
			throw exception("CreateIoCompletionPort(...) failed");
		}
	}
}