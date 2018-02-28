#pragma once

namespace NetIOCP {
	class IServerEvent {
	public:
		IServerEvent() = default;
		IServerEvent(const IServerEvent&) = delete;
		IServerEvent& operator=(const IServerEvent&) = delete;
		virtual ~IServerEvent() = default;
	public:
		virtual void OnError() = 0;
		virtual void PostShutdown() = 0;
		virtual void PostStart() = 0;
		virtual void PreShutdown() = 0;
		virtual void PreStart() = 0;
	};
}
