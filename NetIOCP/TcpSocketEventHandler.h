#pragma once

namespace NetIOCP {
	class TcpSocketEventHandler : public ISocketEvent {
	public:
		class ServerEventHandler : public IServerEvent {
		public:
			ServerEventHandler( TcpSocketEventHandler& handler)
				:mEventHandler(handler) {}
		public:
			void OnError() override {}
			void PostShutdown() override;
			void PostStart() override {}
			void PreShutdown() override;
			void PreStart() override {}
		private:
			TcpSocketEventHandler& mEventHandler;
		};
	public:
		TcpSocketEventHandler() = default;
		~TcpSocketEventHandler() = default;
	public:
		virtual void PreAccept(Socket& socket, IOBuffer& buffer);
		virtual void PostAccept(Socket& socket, IOBuffer& buffer);
		virtual void OnError(Socket& socket) {};
		virtual void PostClose(Socket& socket);
		virtual void PostRead(Socket& socket, IOBuffer& buffer);
		virtual void PostWrite(Socket& socket, IOBuffer& buffer);
		virtual void PreClose(Socket& socket) {};
		virtual void PreRead(Socket& socket, IOBuffer& buffer) {};
		virtual void PreWrite(Socket& socket, IOBuffer& buffer) {};
	private:
		map<SOCKET, Socket*> mSocketSet;
	};
}