#pragma once

class CVIPData : public IPlayerData {
public:
	using IPlayerData::IPlayerData;
	~CVIPData() = default;
public:
	u32 mGem{ 0 };			//玩家当前宝石数
	u32 mTotalGems{ 0 };	//玩家总宝石数
	u32 mTotalCharge{ 0 };	//玩家总充值数
	string mLastChargeTime{ "" };	//玩家最后一次充值时间
};