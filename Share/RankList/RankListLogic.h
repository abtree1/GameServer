#pragma once
template<typename T>
using CompareFunc = bool(*)(const T&, const T&);
template<typename T, typename U>
using GetValueFunc = U(*)(const T&);

template<typename T, typename U>
class CRankListLogic {
public:
	//ʱʱ���� ��ȡ���α仯
	int getRankTo(int from, CompareFunc<T> func) {
		int size = mRankList.size();
		int to = from;
		if (from > 0 && func(mRankList[from], mRankList[from - 1])) {
			//��ǰ�ƶ�
			to = 0;
			for (int i = from - 2; i >= 0; --i) {
				if (!func(mRankList[from], mRankList[i])) {
					to = i + 1;
					break;
				}
			}
		}
		else if (from < size - 1 && !func(mRankList[from], mRankList[from + 1])) {
			//����ƶ�
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
	//ʱʱ���� �ƶ����а�
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
	//�����а�ĩβ�������
	void puahBack(T& data, GetValueFunc<T, U> func) {
		if (mbHasRank)
			data.rank = mRankList.size();
		mRankList.push_back(data);
		mRankListKV[func(data)] = mRankList.size() - 1;
	}
	//�첽���� ���ݱ仯
	void updateRankList(T& data, U& key) {
		mRankListHelp[key] = data;
	}

	//�첽���� �������а�����
	//hasRank ��ʶ��RankData���Ƿ���rank�ֶ�
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

	//�����������а�
	void resort(CompareFunc<T> func, bool resetRank = false) {
		std::sort(mRankList.begin(), mRankList.end(), func);
		if (mRankListSize > 0 && mRankList.size() > mRankListSize)
			mRankList._Pop_back_n(mRankList.size() - mRankListSize);
		//�����rank�ֶζ�����Ҫǿ������
		if (mbHasRank && resetRank) {
			int pos = 0;
			for (auto &it : mRankList) {
				it.rank = pos;
				++pos;
			}
		}
	}
	//�������а���������KV
	void resortKV(GetValueFunc<T, U> func) {
		mRankListKV.clear();
		int pos = 0;
		for (auto &it : mRankList) {
			mRankListKV[func(it)] = pos;
			++pos;
		}
	}
	//��ȡ����
	int getRank(U key) {
		auto it = mRankListKV.find(key);
		if (it == mRankListKV.end())
			return -1;
		return it->second;
	}
	//������а�����
	void clear() {
		mRankList.clear();
		mRankListHelp.clear();
		mRankListKV.clear();
	}
public:
	vector<T> mRankList;      //���а�����
	map<U, int> mRankListKV;  //���ڱ�ʶKey��rank��Ӧ
	map<U, T> mRankListHelp;  //�Ǽ�ʱ���еĸ������л��� 
	bool mbHasRank{ false };  //�Ƿ���rank�ֶ�
	int mRankListSize{ 0 };   //���а����󳤶�
};