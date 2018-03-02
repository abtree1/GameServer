#pragma once
/************************************************************************
	����ͬ�����µ����а�
************************************************************************/

template<typename T>
class IRankListSync {
public:
	//�÷��������������а�Ĳ���
	virtual void Init(bool hasRank, int capacity) {
		mRankListHandle.mbHasRank = hasRank;
		mRankListHandle.mRankListSize = capacity;
	}
	//�������а�����
	virtual void DealRankList(T& data) {
		//��ȡ��ǰ���ݵ�λ��
		int from = mRankListHandle.mRankList.size();  //Ĭ��Ϊ���а�β��
		auto it = mRankListHandle.mRankListKV.find(data.GetId());
		if (it != mRankListHandle.mRankListKV.end()) {
			from = it->second;
			//��������
			auto &oldData = mRankListHandle.mRankList[from];
			oldData = data;
		}
		else {
			mRankListHandle.puahBack(data);
		}
		//�������Ҫ�ƶ�����λ��
		int to = mRankListHandle.getRankTo(from);
		//�ƶ����а�
		mRankListHandle.moveRankList(from, to);
	}
private:
	T *_type_; //�ñ���ֻ���ڻ�ȡId�ֶε�����(Ŀǰ��û�ҵ�����������ȡ)
public:
	//�������а����ݺͲ���
	CRankListLogic<T, decltype(_type_->GetId())> mRankListHandle;
};