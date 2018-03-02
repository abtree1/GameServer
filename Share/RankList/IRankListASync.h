#pragma once
/************************************************************************
�����첽���µ����а�
************************************************************************/

template<typename T>
class IRankListAsync {
	//�÷��������������а�Ĳ���
	virtual void Init(bool hasRank, int capacity) {
		mRankListHandle.mbHasRank = hasRank;
		mRankListHandle.mRankListSize = capacity;
	}
	//��������
	virtual void UpdateRankListData(T& data) {
		mRankListHandle.updateRankList(data);
	}
	//��ʱ����
	virtual void Update() {
		time_t now = CTime::GetTimeStamp();
		if (now > mNextUpdateTime) {
			DealUpdate();
			mNextUpdateTime = now + mTimeSpan;
		}
	}
	//ʵ�ʸ������а�
	virtual void DealUpdate() {
		if (mRankListHandle.dirtyRankList()) {
			mRankListHandle.resort();
			mRankListHandle.resortKV();
		}
	}
private:
	T *___t; //�ñ���ֻ���ڻ�ȡId�ֶε�����(Ŀǰ��û�ҵ�����������ȡ)
public:
	//�������а����ݺͲ���
	CRankListLogic<T, decltype(___t->GetId())> mRankListHandle;
	//�ϴθ������а�ʱ��
	time_t mNextUpdateTime{ 0 };
	UINT mTimeSpan{ 0 };
};