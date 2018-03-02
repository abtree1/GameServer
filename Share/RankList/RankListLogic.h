#pragma once
//template<typename T>
//using CompareFunc = bool(*)(const T&, const T&);
//template<typename T, typename U>
//using GetValueFunc = U(*)(const T&);

template<typename T, typename U>
class CRankListLogic {
public:
	//ʱʱ���� ��ȡ���α仯
	int getRankTo(int from) {
		int size = mRankList.size();
		int to = from;
		if (from > 0 && mRankList[from] > mRankList[from - 1]) {
			//��ǰ�ƶ�
			to = 0;
			for (int i = from - 2; i >= 0; --i) {
				if (mRankList[from] <= mRankList[i]) {
					to = i + 1;
					break;
				}
			}
		}
		else if (from < size - 1 && mRankList[from] <= mRankList[from + 1]) {
			//����ƶ�
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
	//ʱʱ���� �ƶ����а�
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
	//�����а�ĩβ�������
	void puahBack(T& data) {
		if (mbHasRank)
			data.SetRank(mRankList.size());
		mRankList.push_back(data);
		mRankListKV[data.GetId()] = mRankList.size() - 1;
	}
	//�첽���� ���ݱ仯
	void updateRankList(T& data) {
		mRankListHelp[data.GetId()] = data;
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
	void resort(bool resetRank = false) {
		std::sort(mRankList.begin(), mRankList.end());
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
	void resortKV() {
		mRankListKV.clear();
		int pos = 0;
		for (auto &it : mRankList) {
			mRankListKV[it.GetId()] = pos;
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