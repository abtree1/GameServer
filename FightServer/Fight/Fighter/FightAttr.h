#pragma once

#define BitFALSE 0x0
#define BitTRUE 0x1
/************************************************************************
	将战斗属性的bool属性集中防止管理 好处是可节约存储空间和发送数据包大小
************************************************************************/
union UFightBit {
	struct {
		u32 bJiFei : 1;		//击飞
		u32 bJiDao : 1;		//击倒
		u32 bYunXuan : 1;	//眩晕
		u32 bDingShen : 1;	//定身
		u32 bChaoFeng : 1;	//嘲讽
		u32 bChengMo : 1;	//沉默
		u32 bBingDong : 1;	//冰冻
		u32 bKongJu : 1;	//恐惧

		u32 d_bJiFei : 1;		//免疫击飞
		u32 d_bJiDao : 1;		//免疫击倒
		u32 d_bYunXuan : 1;		//免疫眩晕
		u32 d_bDingShen : 1;	//免疫定身
		u32 d_bChaoFeng : 1;	//免疫嘲讽
		u32 d_bChengMo : 1;		//免疫沉默
		u32 d_bBingDong : 1;	//免疫冰冻
		u32 d_bKongJu : 1;		//免疫恐惧

		u32 bWudi : 1;		//无敌
		u32 bLianJi : 1;	//是否可以连击(触发连击后 该值改变)
		u32 bWuShiFangYU : 1;	//无视防御

		u32 UnUse : 13;		//还未使用
	} mBitAttr;
	u32 mValue{ 0 };
};

/************************************************************************
	战斗属性的概率都采用万分比
************************************************************************/
class CFighterAttr {
public:
	//bool属性
	UFightBit mBitAttr;
	//攻击力
	u32 mAttack{ 0 };
	//防御力
	u32 mDefined{ 0 };
	//血量
	u32 mHealth{ 0 };
	//速度
	u32 mSpeed{ 0 };

	//必中率
	float mBiZhongRate{ 0.0f };
	//闪避率
	float mSanBiRate{ 0.0f };

	//伤害加深
	float mHurtIncRate{ 0.0f };
	//伤害减免
	float mHurtDecRate{ 0.0f };

	//暴击率
	float mBaoJiLvRate{ 0.0f };
	//抗暴率
	float mD_BaoJiLvRate{ 0.0f };
	//暴击倍率
	float mBaoJiIncRate{ 0.0f };

	//招架率
	float mZhaoJiaRate{ 0.0f };
	//抗招架率
	float mD_ZhaoJiaRate{ 0.0f };
	//招架减免
	float mZhaoJiaDecRate{ 0.0f };

	//护盾值(代替血量消耗)
	u32 mHuDun{ 0 };
	//吸血
	float mXiXueRate{ 0.0f };
	//伤害反弹
	float mFanTanRate{ 0.0f };
	//连击
	float mLianJiRate{ 0.0f };
public:
	bool IsJiFei(){ return mBitAttr.mBitAttr.bJiFei == BitTRUE; }		//击飞
	bool IsJiDao() { return mBitAttr.mBitAttr.bJiDao == BitTRUE; } 		//击倒
	bool IsYunXuan() { return mBitAttr.mBitAttr.bYunXuan == BitTRUE; }	//眩晕
	bool IsDingShen() { return mBitAttr.mBitAttr.bDingShen == BitTRUE; }	//定身
	bool IsChaoFeng() { return mBitAttr.mBitAttr.bChaoFeng == BitTRUE; }	//嘲讽
	bool IsChengMo() { return mBitAttr.mBitAttr.bChengMo == BitTRUE; }	//沉默
	bool IsBingDong() { return mBitAttr.mBitAttr.bBingDong == BitTRUE; }	//冰冻
	bool IsKongJu() { return mBitAttr.mBitAttr.bKongJu == BitTRUE; }	//恐惧

	void JiFei(bool val = true) { mBitAttr.mBitAttr.bJiFei | (val ? BitTRUE : BitFALSE); }		//击飞
	void JiDao(bool val = true) { mBitAttr.mBitAttr.bJiDao | (val ? BitTRUE : BitFALSE); } 		//击倒
	void YunXuan(bool val = true) { mBitAttr.mBitAttr.bYunXuan | (val ? BitTRUE : BitFALSE); }	//眩晕
	void DingShen(bool val = true) { mBitAttr.mBitAttr.bDingShen | (val ? BitTRUE : BitFALSE); }	//定身
	void ChaoFeng(bool val = true) { mBitAttr.mBitAttr.bChaoFeng | (val ? BitTRUE : BitFALSE); }	//嘲讽
	void ChengMo(bool val = true) { mBitAttr.mBitAttr.bChengMo | (val ? BitTRUE : BitFALSE); }	//沉默
	void BingDong(bool val = true) { mBitAttr.mBitAttr.bBingDong | (val ? BitTRUE : BitFALSE); }	//冰冻
	void KongJu(bool val = true) { mBitAttr.mBitAttr.bKongJu | (val ? BitTRUE : BitFALSE); }	//恐惧

	bool IsDefJiFei() { return mBitAttr.mBitAttr.d_bJiFei == BitTRUE; }		//免疫击飞
	bool IsDefJiDao() { return mBitAttr.mBitAttr.d_bJiDao == BitTRUE; } 		//免疫击倒
	bool IsDefYunXuan() { return mBitAttr.mBitAttr.d_bYunXuan == BitTRUE; }	//免疫眩晕
	bool IsDefDingShen() { return mBitAttr.mBitAttr.d_bDingShen == BitTRUE; }	//免疫定身
	bool IsDefChaoFeng() { return mBitAttr.mBitAttr.d_bChaoFeng == BitTRUE; }	//免疫嘲讽
	bool IsDefChengMo() { return mBitAttr.mBitAttr.d_bChengMo == BitTRUE; }	//免疫沉默
	bool IsDefBingDong() { return mBitAttr.mBitAttr.d_bBingDong == BitTRUE; }	//免疫冰冻
	bool IsDefKongJu() { return mBitAttr.mBitAttr.d_bKongJu == BitTRUE; }	//免疫恐惧

	void DefJiFei(bool val = true) { mBitAttr.mBitAttr.d_bJiFei | (val ? BitTRUE : BitFALSE); }		//免疫击飞
	void DefJiDao(bool val = true) { mBitAttr.mBitAttr.d_bJiDao | (val ? BitTRUE : BitFALSE); } 		//免疫击倒
	void DefYunXuan(bool val = true) { mBitAttr.mBitAttr.d_bYunXuan | (val ? BitTRUE : BitFALSE); }	//免疫眩晕
	void DefDingShen(bool val = true) { mBitAttr.mBitAttr.d_bDingShen | (val ? BitTRUE : BitFALSE); }	//免疫定身
	void DefChaoFeng(bool val = true) { mBitAttr.mBitAttr.d_bChaoFeng | (val ? BitTRUE : BitFALSE); }	//免疫嘲讽
	void DefChengMo(bool val = true) { mBitAttr.mBitAttr.d_bChengMo | (val ? BitTRUE : BitFALSE); }	//免疫沉默
	void DefBingDong(bool val = true) { mBitAttr.mBitAttr.d_bBingDong | (val ? BitTRUE : BitFALSE); }	//免疫冰冻
	void DefKongJu(bool val = true) { mBitAttr.mBitAttr.d_bKongJu | (val ? BitTRUE : BitFALSE); }	//免疫恐惧

	bool IsWuDi() { return mBitAttr.mBitAttr.bWudi == BitTRUE; }		//无敌
	bool IsLianJi() { return mBitAttr.mBitAttr.bLianJi == BitTRUE; } 		//连击
	bool IsWuShiFangYu() { return mBitAttr.mBitAttr.bWuShiFangYU == BitTRUE; }	//无视防御

	void WuDi(bool val = true) { return mBitAttr.mBitAttr.bWudi | (val ? BitTRUE : BitFALSE); }		//无敌
	void LianJi(bool val = true) { return mBitAttr.mBitAttr.bLianJi | (val ? BitTRUE : BitFALSE); } 		//连击
	void WuShiFangYu(bool val = true) { return mBitAttr.mBitAttr.bWuShiFangYU | (val ? BitTRUE : BitFALSE); }	//无视防御

	u32 GetBitValue() { return mBitAttr.mValue; } //获取全部属性值
	void SetBitValue(u32 val) { mBitAttr.mValue = val }; //设置全部属性
	//void UpdateValue(u32 val) { mBitAttr.mValue | val }; //更新部分值
public:
};