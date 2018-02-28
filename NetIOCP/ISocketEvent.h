#pragma once

namespace NetIOCP {
	class ISocketEvent {
	public:
		ISocketEvent() = default;
		ISocketEvent(const ISocketEvent&) = delete;
		ISocketEvent& operator=(const ISocketEvent&) = delete;
		virtual ~ISocketEvent() = default;
	public:
		virtual void PreAccept(Socket& socket, IOBuffer& buffer) = 0;
		virtual void PostAccept(Socket& socket, IOBuffer& buffer) = 0;
		virtual void OnError(Socket& socket) = 0;
		virtual void PostClose(Socket& socket) = 0;
		virtual void PostRead(Socket& socket, IOBuffer& buffer) = 0;
		virtual void PostWrite(Socket& socket, IOBuffer& buffer) = 0;
		virtual void PreClose(Socket& socket) = 0;
		virtual void PreRead(Socket& socket, IOBuffer& buffer) = 0;
		virtual void PreWrite(Socket& socket, IOBuffer& buffer) = 0;
	};
}