#pragma once

namespace NetIOCP {
	class ISocketEventDispatcher;

	class ISocketFactory {
	public:
		virtual Socket* Create(ISocketEventDispatcher* dispatcher) = 0;
	};
}
