#pragma once

namespace NetIOCP {
	/*
		该类主要用于IOCP的工作器线程的创建和管理
	*/
	class DefaultTaskFactory : public ITaskFactory {
	public:
		// 默认为 number of processor x 2
		DefaultTaskFactory(unsigned int nTask = 0);
		~DefaultTaskFactory() = default;
	public:
		//创建IOCP的工作器线程
		virtual unsigned int Create(ISocketEventDispatcher* dispatcher) override;
		//获取IOCP的工作器线程的数量
		virtual unsigned int GetTaskCount() override { return mNumberOfTask; }
	private:
		//工作器线程的update
		static void RunDispatcher(ISocketEventDispatcher* dispatcher);
	private:
		//需要创建的工作器线程数量
		unsigned int mNumberOfTask{ 0 };
	};
}