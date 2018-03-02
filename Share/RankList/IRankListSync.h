#pragma once
/************************************************************************
	处理同步更新的排行榜
************************************************************************/

template<typename T>
class IRankListSync {
public:
	//该方法用于设置排行榜的参数
	virtual void Init(bool hasRank, int capacity) {
		mRankListHandle.mbHasRank = hasRank;
		mRankListHandle.mRankListSize = capacity;
	}
	//更新排行榜数据
	virtual void DealRankList(T& data) {
		//获取当前数据的位置
		int from = mRankListHandle.mRankList.size();  //默认为排行榜尾部
		auto it = mRankListHandle.mRankListKV.find(data.GetId());
		if (it != mRankListHandle.mRankListKV.end()) {
			from = it->second;
			//更新数据
			auto &oldData = mRankListHandle.mRankList[from];
			oldData = data;
		}
		else {
			mRankListHandle.puahBack(data);
		}
		//计算出需要移动到的位置
		int to = mRankListHandle.getRankTo(from);
		//移动排行榜
		mRankListHandle.moveRankList(from, to);
	}
private:
	T *_type_; //该变量只用于获取Id字段的类型(目前我没找到其它方法获取)
public:
	//保存排行榜数据和操作
	CRankListLogic<T, decltype(_type_->GetId())> mRankListHandle;
};