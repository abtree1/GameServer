#pragma once
template<typename T>
using CompareFunc = bool(*)(const T&, const T&);
template<typename T, typename U>
using GetValueFunc = U(*)(const T&);

template<typename T, typename U>
class CRankListLogic {
public:
	//时时排行 获取名次变化
	int getRankTo(int from, CompareFunc<T> func) {
		int size = mRankList.size();
		int to = from;
		if (from > 0 && func(mRankList[from], mRankList[from - 1])) {
			//向前移动
			to = 0;
			for (int i = from - 2; i >= 0; --i) {
				if (!func(mRankList[from], mRankList[i])) {
					to = i + 1;
					break;
				}
			}
		}
		else if (from < size - 1 && !func(mRankList[from], mRankList[from + 1])) {
			//向后移动
			to = size - 1;
			for (int i = from + 1; i < size; ++i) {
				if (func(mRankList[from], mRankList[i])) {
					to = i - 1;
					break;
				}
			}
		}
		return to;
	}
	//时时排行 移动排行榜
	void moveRankList(int from, int to, GetValueFunc<T, U> func) {
		T data = mRankList[from];
		if (from > to) {
			for (int i = from; i > to; --i) {
				mRankList[i] = mRankList[i - 1];
				mRankListKV[func(mRankList[i])] = i;
			}
			mRankList[to] = data;
			mRankListKV[func(data)] = to;
		}
		else if (from < to) {
			for (int i = from; i < to; ++i) {
				mRankList[i] = mRankList[i + 1];
				mRankListKV[func(mRankList[i])] = i;
			}
			mRankList[to] = data;
			mRankListKV[func(data)] = to;
		}
		if (mRankListSize > 0) {
			while (mRankList.size() > mRankListSize) {
				mRankListKV.erase(func(mRankList[mRankList.size() - 1]));
				mRankList.pop_back();
			}
		}
	}
	//在排行榜末尾添加数据
	void puahBack(T& data, GetValueFunc<T, U> func) {
		if (mbHasRank)
			data.rank = mRankList.size();
		mRankList.push_back(data);
		mRankListKV[func(data)] = mRankList.size() - 1;
	}
	//异步排行 数据变化
	void updateRankList(T& data, U& key) {
		mRankListHelp[key] = data;
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
	void resort(CompareFunc<T> func, bool resetRank = false) {
		std::sort(mRankList.begin(), mRankList.end(), func);
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
	void resortKV(GetValueFunc<T, U> func) {
		mRankListKV.clear();
		int pos = 0;
		for (auto &it : mRankList) {
			mRankListKV[func(it)] = pos;
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