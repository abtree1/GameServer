#pragma once

namespace NetIOCP {
	class Statistics {
	public:
		// ��ǰ�������еĹ����߳���
		static unsigned long AliveTask;
		// ��ǰδ��ɵ�д����
		static unsigned long PendingWrites;
		// ��ǰδ��ɵĶ�����
		static unsigned long PendingReads;
		// ��ǰ�����ӵ� socket ��
		static unsigned long ConnectingSockets;
	};
}