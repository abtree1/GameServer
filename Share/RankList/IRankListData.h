#pragma once

/************************************************************************
	RankList Data 为保存排行榜数据的结构 是构成特定排行榜的基础
	每个排行榜数据结构都至少继承于IRankListBase或其子类
************************************************************************/
template<typename T, typename U>
struct IRankListBase {
	virtual T &operator=(const T &) = 0;
	//友元函数只需要声明 故不能为虚函数
	friend bool operator>(const T &, const T &);
	friend bool operator>=(const T &, const T &);
	friend bool operator<(const T &, const T &);
	friend bool operator<=(const T &, const T &);
	virtual U GetId() = 0;
	virtual void SetRank(UINT rank) {}
};

//实现一个通用的 可从该实现继承
struct IRankListImpl : public IRankListBase<IRankListImpl, UINT>{
	UINT mRank{ 0 };  //排名
	UINT mScore{ 0 }; //用于排名的值 
	UINT mId{ 0 };	//该数据块的标识
	virtual IRankListImpl &operator=(const IRankListImpl &);
	virtual UINT GetId() override;
	virtual void SetRank(UINT rank) override { this->mRank = rank; };
};
#ifdef _DEBUG
struct SRankListData :public IRankListImpl {
	string tstr;  //测试数据
	UINT tint;    //测试数据

	SRankListData &operator=(const SRankListData &);
};
#endif