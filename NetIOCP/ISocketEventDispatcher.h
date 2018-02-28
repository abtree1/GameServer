#pragma once

namespace NetIOCP {
	class ISocketEventDispatcher {
	public:
		ISocketEventDispatcher() = default;
		ISocketEventDispatcher(const ISocketEventDispatcher&) = delete;
		ISocketEventDispatcher& operator=(const ISocketEventDispatcher&) = delete;
		virtual ~ISocketEventDispatcher() = default;
	public:
		virtual void Process() = 0;
		virtual void Register(ISocketEvent* handler) = 0;
	public:
		virtual void TriggerPreAccept(Socket& socket, IOBuffer& buffer) = 0;
		virtual void TriggerPostAccept(Socket& socket, IOBuffer& buffer) = 0;
		virtual void TriggerError(Socket& socket) = 0;
		virtual void TriggerPostClose(Socket& socket) = 0;
		virtual void TriggerPostRead(Socket& socket, IOBuffer& buffer) = 0;
		virtual void TriggerPostWrite(Socket& socket, IOBuffer& buffer) = 0;
		virtual void TriggerPreClose(Socket& socket) = 0;
		virtual void TriggerPreRead(Socket& socket, IOBuffer& buffer) = 0;
		virtual void TriggerPreWrite(Socket& socket, IOBuffer& buffer) = 0;
	};
}