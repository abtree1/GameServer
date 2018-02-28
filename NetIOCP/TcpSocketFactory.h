#pragma once

namespace NetIOCP {
	class TcpSocketFactory : public ISocketFactory {
	public:
		Socket* Create(ISocketEventDispatcher* dispatcher) override;
	};
}