#pragma once
//template<typename T>
//using CompareFunc = bool(*)(const T&, const T&);
//template<typename T, typename U>
//using GetValueFunc = U(*)(const T&);

template<typename T, typename U>
class CRankListLogic {
public:
	//时时排行 获取名次变化
	int getRankTo(int from) {
		int size = mRankList.size();
		int to = from;
		if (from > 0 && mRankList[from] > mRankList[from - 1]) {
			//向前移动
			to = 0;
			for (int i = from - 2; i >= 0; --i) {
				if (mRankList[from] <= mRankList[i]) {
					to = i + 1;
					break;
				}
			}
		}
		else if (from < size - 1 && mRankList[from] <= mRankList[from + 1]) {
			//向后移动
			to = size - 1;
			for (int i = from + 1; i < size; ++i) {
				if (mRankList[from] > mRankList[i]) {
					to = i - 1;
					break;
				}
			}
		}
		return to;
	}
	//时时排行 移动排行榜
	void moveRankList(int from, int to) {
		T data = mRankList[from];
		if (from > to) {
			for (int i = from; i > to; --i) {
				mRankList[i] = mRankList[i - 1];
				mRankListKV[mRankList[i].GetId()] = i;
			}
			mRankList[to] = data;
			mRankListKV[data.GetId()] = to;
		}
		else if (from < to) {
			for (int i = from; i < to; ++i) {
				mRankList[i] = mRankList[i + 1];
				mRankListKV[mRankList[i].GetId()] = i;
			}
			mRankList[to] = data;
			mRankListKV[data.GetId()] = to;
		}
		if (mRankListSize > 0) {
			while (mRankList.size() > mRankListSize) {
				mRankListKV.erase(mRankList[mRankList.size() - 1].GetId());
				mRankList.pop_back();
			}
		}
	}
	//在排行榜末尾添加数据
	void puahBack(T& data) {
		if (mbHasRank)
			data.SetRank(mRankList.size());
		mRankList.push_back(data);
		mRankListKV[data.GetId()] = mRankList.size() - 1;
	}
	//异步排行 数据变化
	void updateRankList(T& data) {
		mRankListHelp[data.GetId()] = data;
	}

	//异步排序 更新排行榜数据
	//hasRank 标识在RankData中是否有rank字段
	bool dirtyRankList() {
		if (mRankListHelp.empty())
			return false;
		for (auto &it : mRankListHelp) {
			auto itkv = mRankListKV.find(it.first);
			if (itkv != mRankListKV.end()) {
				mRankList[itkv->second] = it.second;
			}
			else {
				if (mbHasRank)
					it.second.rank = mRankList.size();
				mRankList.push_back(it.second);
			}
		}
		mRankListHelp.clear();
		return true;
	}

	//重新生成排行榜
	void resort(bool resetRank = false) {
		std::sort(mRankList.begin(), mRankList.end());
		if (mRankListSize > 0 && mRankList.size() > mRankListSize)
			mRankList._Pop_back_n(mRankList.size() - mRankListSize);
		//如果有rank字段而且需要强制重排
		if (mbHasRank && resetRank) {
			int pos = 0;
			for (auto &it : mRankList) {
				it.rank = pos;
				++pos;
			}
		}
	}
	//根据排行榜重新生成KV
	void resortKV() {
		mRankListKV.clear();
		int pos = 0;
		for (auto &it : mRankList) {
			mRankListKV[it.GetId()] = pos;
			++pos;
		}
	}
	//获取名次
	int getRank(U key) {
		auto it = mRankListKV.find(key);
		if (it == mRankListKV.end())
			return -1;
		return it->second;
	}
	//清除排行榜数据
	void clear() {
		mRankList.clear();
		mRankListHelp.clear();
		mRankListKV.clear();
	}

public:
	vector<T> mRankList;      //排行榜数据
	map<U, int> mRankListKV;  //用于标识Key和rank对应
	map<U, T> mRankListHelp;  //非即时排行的辅助排行缓存 
	bool mbHasRank{ false };  //是否有rank字段
	int mRankListSize{ 0 };   //排行榜的最大长度
};