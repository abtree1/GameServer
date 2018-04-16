#pragma once

namespace NetIOCP {
	/*
		������Ҫִ��iocp���߼�
	*/
	class ISocketEventDispatcher {
	public:
		ISocketEventDispatcher() = default;
		ISocketEventDispatcher(const ISocketEventDispatcher&) = delete;
		ISocketEventDispatcher& operator=(const ISocketEventDispatcher&) = delete;
		virtual ~ISocketEventDispatcher() = default;
	public:
		//ִ��iocp����
		virtual void Process() = 0;
		//ע�ᴦ���¼�
		virtual void Register(ISocketEvent* handler) = 0;
	public:
		//������socketǰ����
		virtual void TriggerPreAccept(Socket& socket, IOBuffer& buffer) = 0;
		//������socket�󴥷�
		virtual void TriggerPostAccept(Socket& socket, IOBuffer& buffer) = 0;
		//��������ʱ����
		virtual void TriggerError(Socket& socket) = 0;
		//���͹ر�ʱ����
		virtual void TriggerPostClose(Socket& socket) = 0;
		//��ȡ���ݺ󴥷�
		virtual void TriggerPostRead(Socket& socket, IOBuffer& buffer) = 0;
		//�������ݺ󴥷�
		virtual void TriggerPostWrite(Socket& socket, IOBuffer& buffer) = 0;
		//�ر�ǰ����
		virtual void TriggerPreClose(Socket& socket) = 0;
		//��ȡǰ����
		virtual void TriggerPreRead(Socket& socket, IOBuffer& buffer) = 0;
		//��ȡ�󴥷�
		virtual void TriggerPreWrite(Socket& socket, IOBuffer& buffer) = 0;
	};
}