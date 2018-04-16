#include "stdafx.h"

namespace NetIOCP {
	DefaultTaskFactory::DefaultTaskFactory(unsigned int nTask) {
		if (0 == mNumberOfTask) {
			SYSTEM_INFO info;
			memset(&info, 0, sizeof(info));
			GetSystemInfo(&info);
			mNumberOfTask = info.dwNumberOfProcessors * 2;
		}
	}

	void DefaultTaskFactory::RunDispatcher(ISocketEventDispatcher* dispatcher) {
		//ISocketEventDispatcher* dispatcher = static_cast<ISocketEventDispatcher*>(dsp);
		dispatcher->Process();
	}

	unsigned int DefaultTaskFactory::Create(ISocketEventDispatcher* dispatcher) {
		for (int i = 0; i < mNumberOfTask; ++i) {
			//创建线程
			std::thread th(DefaultTaskFactory::RunDispatcher, dispatcher);
			th.detach(); //detach不等待子线程执行完毕
			//_beginthread(DefaultTaskFactory::RunDispatcher, 0, (void*)&dispatcher);
		}
		return mNumberOfTask;
	}
}