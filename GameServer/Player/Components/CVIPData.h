#pragma once

class CVIPData : public IPlayerData {
public:
	using IPlayerData::IPlayerData;
	~CVIPData() = default;
public:
	u32 mGem{ 0 };			//��ҵ�ǰ��ʯ��
	u32 mTotalGems{ 0 };	//����ܱ�ʯ��
	u32 mTotalCharge{ 0 };	//����ܳ�ֵ��
	string mLastChargeTime{ "" };	//������һ�γ�ֵʱ��
};