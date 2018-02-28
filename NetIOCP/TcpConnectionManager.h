#pragma once

namespace NetIOCP {
	class TcpConnectionManager : public IConnectionManager {
	private:
		//这个event只需要处理socket的建立连接和断开连接
		class SocketEventHandler : public ISocketEvent {
		public:
			SocketEventHandler(TcpConnectionManager* mtr)
				:mMonitor(mtr) {

			}
		public:
			virtual void PreAccept(Socket& socket, IOBuffer& buffer) override;
			virtual void PostAccept(Socket& socket, IOBuffer& buffer) override;
			virtual void OnError(Socket& socket) override {}
			virtual void PostClose(Socket& socket) override;
			virtual void PostRead(Socket& socket, IOBuffer& buffer) override {}
			virtual void PostWrite(Socket& socket, IOBuffer& buffer) override {}
			virtual void PreClose(Socket& socket) override {}
			virtual void PreRead(Socket& socket, IOBuffer& buffer) override {}
			virtual void PreWrite(Socket& socket, IOBuffer& buffer) override {}
		private:
			TcpConnectionManager* mMonitor;
		};
	public:
		TcpConnectionManager(ISocketEventDispatcher* dsp);
		~TcpConnectionManager() = default;
	public:
		virtual void OnDisconnected(Socket* socket, IOBuffer* buffer) override;
		virtual void Process() override;
	private:
		bool PostAcceptRequest();
		bool PostAcceptRequest(Socket* socket, IOBuffer* buffer);
	private:
		ISocketEventDispatcher* mDispatcher;
		ISocketFactory* mFactory;
	};
}