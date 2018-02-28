#pragma once

namespace NetIOCP {
	class ISocketEventDispatcher;

	class ITaskFactory {
	public:
		ITaskFactory() = default;
		ITaskFactory(const ITaskFactory&) = delete;
		ITaskFactory& operator=(const ITaskFactory&) = delete;
		virtual ~ITaskFactory() = default;
	public:
		virtual unsigned int Create(ISocketEventDispatcher*) = 0;
		virtual unsigned int GetTaskCount() = 0;
	};
}
