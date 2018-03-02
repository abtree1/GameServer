#pragma once

template<typename T, typename U>
struct IRankListBase {
	virtual T &operator=(const T &) = 0;
	//��Ԫ����ֻ��Ҫ���� �ʲ���Ϊ�麯��
	friend bool operator>(const T &, const T &);
	friend bool operator>=(const T &, const T &);
	friend bool operator<(const T &, const T &);
	friend bool operator<=(const T &, const T &);
	virtual U GetId() = 0;
	virtual void SetRank(UINT rank) {}
};

//ʵ��һ��ͨ�õ� �ɴӸ�ʵ�ּ̳�
struct IRankListImpl : public IRankListBase<IRankListImpl, UINT>{
	UINT mRank{ 0 };  //����
	UINT mScore{ 0 }; //����������ֵ 
	UINT mId{ 0 };	//�����ݿ�ı�ʶ
	virtual IRankListImpl &operator=(const IRankListImpl &);
	virtual UINT GetId() override;
	virtual void SetRank(UINT rank) override { this->mRank = rank; };
};

struct SRankListData :public IRankListImpl {
	string tstr;  //��������
	UINT tint;    //��������

	SRankListData &operator=(const SRankListData &);
};