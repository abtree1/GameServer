#pragma once

#ifdef NETIOCP_EXPORTS
#define  DLL_CPP_API __declspec(dllexport)
#else
#define DLL_CPP_API __declspec(dllimport)
#endif
/*
	�����Ľӿ� ��������罻��
*/
namespace NetIOCP {
	//����Ϊ�ڲ����ݸ��ⲿ��session�ӿ�
	class DLL_CPP_API ISession {
	public:
		//���������õĽӿ�
		virtual bool __stdcall OnSend(string&) = 0;
		//���������õĽӿ�
		virtual bool __stdcall OnRecv(string&) = 0;
		//��ȡsessionid
		virtual int __stdcall GetSessionId() = 0;
		//�Ͽ�����
		virtual bool __stdcall Disconnect() = 0;
	};

	//���������ⲿ�̳�
	class DLL_CPP_API IConnection {
	public:
		//�����ӵ���ʱ���ⲿ�ص�
		virtual void __stdcall OnConnection(ISession*) = 0;
		//���ӹر�ʱ���ⲿ�ص�
		virtual void __stdcall OnDesconnection(ISession*) = 0;
	};
	/*
		session manager ���ⲿʹ�õĽӿ�
	*/
	class DLL_CPP_API ISessionManager {
	public:
		//��session managerע���ⲿ���󣬹��ص�ʱʹ��
		virtual void registerHandle(IConnection* pconn) = 0;
		/*
		��ʼiocp����
		taskcount = 0 �����ϵͳ���������߳�
		*/
		virtual bool start(string ip, int port, int taskcount) = 0;
		//iocp�Ƿ��Ѿ���ʼ����
		virtual bool isStartup() = 0;
		//�ر�iocp
		virtual void stop() = 0;
		//�Ƿ�iocp���ڹر�״̬
		virtual bool isShutting() = 0;
		//������һ��server������
		virtual ISession* Connect(string ip, int port) = 0;
	};
	//�ⲿ���ڻ�ȡsession manager�Ķ���ʵ��
	extern DLL_CPP_API ISessionManager* __stdcall gGetSessionMgr();
	extern DLL_CPP_API void __stdcall gDestorySessionMgr();
}
