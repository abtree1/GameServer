#pragma once

namespace NetIOCP {
	/*
		该类主要执行iocp的逻辑
	*/
	class ISocketEventDispatcher {
	public:
		ISocketEventDispatcher() = default;
		ISocketEventDispatcher(const ISocketEventDispatcher&) = delete;
		ISocketEventDispatcher& operator=(const ISocketEventDispatcher&) = delete;
		virtual ~ISocketEventDispatcher() = default;
	public:
		//执行iocp调度
		virtual void Process() = 0;
		//注册处理事件
		virtual void Register(ISocketEvent* handler) = 0;
	public:
		//接收新socket前触发
		virtual void TriggerPreAccept(Socket& socket, IOBuffer& buffer) = 0;
		//接收新socket后触发
		virtual void TriggerPostAccept(Socket& socket, IOBuffer& buffer) = 0;
		//发生错误时触发
		virtual void TriggerError(Socket& socket) = 0;
		//发送关闭时触发
		virtual void TriggerPostClose(Socket& socket) = 0;
		//读取数据后触发
		virtual void TriggerPostRead(Socket& socket, IOBuffer& buffer) = 0;
		//发送数据后触发
		virtual void TriggerPostWrite(Socket& socket, IOBuffer& buffer) = 0;
		//关闭前触发
		virtual void TriggerPreClose(Socket& socket) = 0;
		//读取前触发
		virtual void TriggerPreRead(Socket& socket, IOBuffer& buffer) = 0;
		//读取后触发
		virtual void TriggerPreWrite(Socket& socket, IOBuffer& buffer) = 0;
	};
}