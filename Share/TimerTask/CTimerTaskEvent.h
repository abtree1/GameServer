#pragma once
//����Timer Task �����а�
struct STimerTaskData : public IRankListBase<STimerTaskData, UINT> {
	UINT id{ 0 };    //Ψһ��ʶ����
	UINT time{ 0 };	//���񴥷�ʱ��
	ETimerTaskType type{ ETTT_None };  //timer task ������
	CTimeTaskData params;  //��������

	STimerTaskData &operator=(const STimerTaskData&) override;
	UINT GetId() override;
};
//timer task ����ʱʱˢ�»���
class CTimerTaskEvent : public IRankListSync<STimerTaskData> {
public:
	void DelEvent(int pos);  //ɾ��ָ��λ�õ���
	void DelTail(); //ɾ��β�ϵ�����ȴ�����
	STimerTaskData* GetBack(); 
};