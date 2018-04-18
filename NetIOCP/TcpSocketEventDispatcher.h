#pragma once

namespace NetIOCP {
	class TcpSocketEventDispatcher : public ISocketEventDispatcher {
	public:
		TcpSocketEventDispatcher() = default;
		virtual ~TcpSocketEventDispatcher();
	public:
		virtual void Process() override;
		virtual void Register(ISocketEvent* handler) override;
	public:
		virtual void TriggerPreAccept(Socket& socket, IOBuffer& buffer) override;
		virtual void TriggerPostAccept(Socket& socket, IOBuffer& buffer) override;
		virtual void TriggerError(Socket& socket) override;
		virtual void TriggerPostClose(Socket& socket) override;
		virtual void TriggerPostRead(Socket& socket, IOBuffer& buffer) override;
		virtual void TriggerPostWrite(Socket& socket, IOBuffer& buffer) override;
		virtual void TriggerPreClose(Socket& socket) override;
		virtual void TriggerPreRead(Socket& socket, IOBuffer& buffer) override;
		virtual void TriggerPreWrite(Socket& socket, IOBuffer& buffer) override;
	private:
		//…Ë÷√socketµƒ‘∂∂Àµÿ÷∑
		void UpdateSocket(Socket& skt, IOBuffer& buffer);
	private:
		vector<ISocketEvent*> mHandlers;
		bool mbRunning{ false };
	};
}