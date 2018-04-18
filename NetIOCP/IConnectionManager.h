#pragma once

namespace NetIOCP {
	class IConnectionManager {
	public:
		IConnectionManager() = default;
		IConnectionManager(const IConnectionManager&) = delete;
		IConnectionManager& operator=(const IConnectionManager&) = delete;
		virtual ~IConnectionManager() = default;
	public:
		virtual void OnDisconnected(Socket* socket, IOBuffer* buffer) = 0;
		virtual void Process() = 0;
	public:
		virtual Socket* Connect(string ip, int port) = 0;
	};
}