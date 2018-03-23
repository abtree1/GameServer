#pragma once

class CPlayer {
public:
	CPlayer() = default;
	~CPlayer() = default;
public:
	//基础属性
	u32 mId{ 0 };			//玩家id
	string mName{ "" };		//玩家名称
	string mAccount{ "" };	//玩家帐号
	u32 mServerId{ 0 };		//玩家服务器id（合服后不变）
	u32 mPlatform{ 0 };		//玩家平台代号（sdk使用）
	string mCreateTime{ "" };	//创建时间
	string mOnlineTime{ "" };	//最后一次上线时间
	string mOfflineTime{ "" };	//最后一次下线时间
public:
	//扩展属性
	u32 mLevel{ 0 };	// 等级
	u32 mResId{ 0 };	// 头像
	u32 mCoin{ 0 };		// 金币
	u32 mExp{ 0 };		// 经验
public:
	//网络
	CSession* mpSession{ nullptr }; //客户端的session
/************************************************************************/
//组件部分
public:
	//获取组件
	CVIPData* GetVipData() { return &mVipData; }
private:
	//添加组件
	CVIPData mVipData{ this };
/************************************************************************/
};
