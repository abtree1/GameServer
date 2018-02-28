#pragma once

namespace NetIOCP {
	class DefaultTaskFactory : public ITaskFactory {
	public:
		// д╛хон╙ number of processor x 2
		DefaultTaskFactory(unsigned int nTask = 0);
		~DefaultTaskFactory() = default;
	public:
		virtual unsigned int Create(ISocketEventDispatcher* dispatcher) override;
		virtual unsigned int GetTaskCount() override { return mNumberOfTask; }
	private:
		static void RunDispatcher(ISocketEventDispatcher* dispatcher);
	private:
		unsigned int mNumberOfTask{ 0 };
	};
}