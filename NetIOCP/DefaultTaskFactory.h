#pragma once

namespace NetIOCP {
	/*
		������Ҫ����IOCP�Ĺ������̵߳Ĵ����͹���
	*/
	class DefaultTaskFactory : public ITaskFactory {
	public:
		// Ĭ��Ϊ number of processor x 2
		DefaultTaskFactory(unsigned int nTask = 0);
		~DefaultTaskFactory() = default;
	public:
		//����IOCP�Ĺ������߳�
		virtual unsigned int Create(ISocketEventDispatcher* dispatcher) override;
		//��ȡIOCP�Ĺ������̵߳�����
		virtual unsigned int GetTaskCount() override { return mNumberOfTask; }
	private:
		//�������̵߳�update
		static void RunDispatcher(ISocketEventDispatcher* dispatcher);
	private:
		//��Ҫ�����Ĺ������߳�����
		unsigned int mNumberOfTask{ 0 };
	};
}