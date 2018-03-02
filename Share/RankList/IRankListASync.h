#pragma once
/************************************************************************
处理异步更新的排行榜
************************************************************************/

template<typename T>
class IRankListAsync {
	//该方法用于设置排行榜的参数
	virtual void Init(bool hasRank, int capacity) {
		mRankListHandle.mbHasRank = hasRank;
		mRankListHandle.mRankListSize = capacity;
	}
	//更新数据
	virtual void UpdateRankListData(T& data) {
		mRankListHandle.updateRankList(data);
	}
	//定时更新
	virtual void Update() {
		time_t now = CTime::GetTimeStamp();
		if (now > mNextUpdateTime) {
			DealUpdate();
			mNextUpdateTime = now + mTimeSpan;
		}
	}
	//实际更新排行榜
	virtual void DealUpdate() {
		if (mRankListHandle.dirtyRankList()) {
			mRankListHandle.resort();
			mRankListHandle.resortKV();
		}
	}
private:
	T *___t; //该变量只用于获取Id字段的类型(目前我没找到其它方法获取)
public:
	//保存排行榜数据和操作
	CRankListLogic<T, decltype(___t->GetId())> mRankListHandle;
	//上次更新排行榜时间
	time_t mNextUpdateTime{ 0 };
	UINT mTimeSpan{ 0 };
};