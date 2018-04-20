#pragma once

#define BitFALSE 0x0
#define BitTRUE 0x1
/************************************************************************
	��ս�����Ե�bool���Լ��з�ֹ���� �ô��ǿɽ�Լ�洢�ռ�ͷ������ݰ���С
************************************************************************/
union UFightBit {
	struct {
		u32 bJiFei : 1;		//����
		u32 bJiDao : 1;		//����
		u32 bYunXuan : 1;	//ѣ��
		u32 bDingShen : 1;	//����
		u32 bChaoFeng : 1;	//����
		u32 bChengMo : 1;	//��Ĭ
		u32 bBingDong : 1;	//����
		u32 bKongJu : 1;	//�־�

		u32 d_bJiFei : 1;		//���߻���
		u32 d_bJiDao : 1;		//���߻���
		u32 d_bYunXuan : 1;		//����ѣ��
		u32 d_bDingShen : 1;	//���߶���
		u32 d_bChaoFeng : 1;	//���߳���
		u32 d_bChengMo : 1;		//���߳�Ĭ
		u32 d_bBingDong : 1;	//���߱���
		u32 d_bKongJu : 1;		//���߿־�

		u32 bWudi : 1;		//�޵�
		u32 bLianJi : 1;	//�Ƿ��������(���������� ��ֵ�ı�)
		u32 bWuShiFangYU : 1;	//���ӷ���

		u32 UnUse : 13;		//��δʹ��
	} mBitAttr;
	u32 mValue{ 0 };
};

/************************************************************************
	ս�����Եĸ��ʶ�������ֱ�
************************************************************************/
class CFighterAttr {
public:
	//bool����
	UFightBit mBitAttr;
	//������
	u32 mAttack{ 0 };
	//������
	u32 mDefined{ 0 };
	//Ѫ��
	u32 mHealth{ 0 };
	//�ٶ�
	u32 mSpeed{ 0 };

	//������
	float mBiZhongRate{ 0.0f };
	//������
	float mSanBiRate{ 0.0f };

	//�˺�����
	float mHurtIncRate{ 0.0f };
	//�˺�����
	float mHurtDecRate{ 0.0f };

	//������
	float mBaoJiLvRate{ 0.0f };
	//������
	float mD_BaoJiLvRate{ 0.0f };
	//��������
	float mBaoJiIncRate{ 0.0f };

	//�м���
	float mZhaoJiaRate{ 0.0f };
	//���м���
	float mD_ZhaoJiaRate{ 0.0f };
	//�мܼ���
	float mZhaoJiaDecRate{ 0.0f };

	//����ֵ(����Ѫ������)
	u32 mHuDun{ 0 };
	//��Ѫ
	float mXiXueRate{ 0.0f };
	//�˺�����
	float mFanTanRate{ 0.0f };
	//����
	float mLianJiRate{ 0.0f };
public:
	bool IsJiFei(){ return mBitAttr.mBitAttr.bJiFei == BitTRUE; }		//����
	bool IsJiDao() { return mBitAttr.mBitAttr.bJiDao == BitTRUE; } 		//����
	bool IsYunXuan() { return mBitAttr.mBitAttr.bYunXuan == BitTRUE; }	//ѣ��
	bool IsDingShen() { return mBitAttr.mBitAttr.bDingShen == BitTRUE; }	//����
	bool IsChaoFeng() { return mBitAttr.mBitAttr.bChaoFeng == BitTRUE; }	//����
	bool IsChengMo() { return mBitAttr.mBitAttr.bChengMo == BitTRUE; }	//��Ĭ
	bool IsBingDong() { return mBitAttr.mBitAttr.bBingDong == BitTRUE; }	//����
	bool IsKongJu() { return mBitAttr.mBitAttr.bKongJu == BitTRUE; }	//�־�

	void JiFei(bool val = true) { mBitAttr.mBitAttr.bJiFei | (val ? BitTRUE : BitFALSE); }		//����
	void JiDao(bool val = true) { mBitAttr.mBitAttr.bJiDao | (val ? BitTRUE : BitFALSE); } 		//����
	void YunXuan(bool val = true) { mBitAttr.mBitAttr.bYunXuan | (val ? BitTRUE : BitFALSE); }	//ѣ��
	void DingShen(bool val = true) { mBitAttr.mBitAttr.bDingShen | (val ? BitTRUE : BitFALSE); }	//����
	void ChaoFeng(bool val = true) { mBitAttr.mBitAttr.bChaoFeng | (val ? BitTRUE : BitFALSE); }	//����
	void ChengMo(bool val = true) { mBitAttr.mBitAttr.bChengMo | (val ? BitTRUE : BitFALSE); }	//��Ĭ
	void BingDong(bool val = true) { mBitAttr.mBitAttr.bBingDong | (val ? BitTRUE : BitFALSE); }	//����
	void KongJu(bool val = true) { mBitAttr.mBitAttr.bKongJu | (val ? BitTRUE : BitFALSE); }	//�־�

	bool IsDefJiFei() { return mBitAttr.mBitAttr.d_bJiFei == BitTRUE; }		//���߻���
	bool IsDefJiDao() { return mBitAttr.mBitAttr.d_bJiDao == BitTRUE; } 		//���߻���
	bool IsDefYunXuan() { return mBitAttr.mBitAttr.d_bYunXuan == BitTRUE; }	//����ѣ��
	bool IsDefDingShen() { return mBitAttr.mBitAttr.d_bDingShen == BitTRUE; }	//���߶���
	bool IsDefChaoFeng() { return mBitAttr.mBitAttr.d_bChaoFeng == BitTRUE; }	//���߳���
	bool IsDefChengMo() { return mBitAttr.mBitAttr.d_bChengMo == BitTRUE; }	//���߳�Ĭ
	bool IsDefBingDong() { return mBitAttr.mBitAttr.d_bBingDong == BitTRUE; }	//���߱���
	bool IsDefKongJu() { return mBitAttr.mBitAttr.d_bKongJu == BitTRUE; }	//���߿־�

	void DefJiFei(bool val = true) { mBitAttr.mBitAttr.d_bJiFei | (val ? BitTRUE : BitFALSE); }		//���߻���
	void DefJiDao(bool val = true) { mBitAttr.mBitAttr.d_bJiDao | (val ? BitTRUE : BitFALSE); } 		//���߻���
	void DefYunXuan(bool val = true) { mBitAttr.mBitAttr.d_bYunXuan | (val ? BitTRUE : BitFALSE); }	//����ѣ��
	void DefDingShen(bool val = true) { mBitAttr.mBitAttr.d_bDingShen | (val ? BitTRUE : BitFALSE); }	//���߶���
	void DefChaoFeng(bool val = true) { mBitAttr.mBitAttr.d_bChaoFeng | (val ? BitTRUE : BitFALSE); }	//���߳���
	void DefChengMo(bool val = true) { mBitAttr.mBitAttr.d_bChengMo | (val ? BitTRUE : BitFALSE); }	//���߳�Ĭ
	void DefBingDong(bool val = true) { mBitAttr.mBitAttr.d_bBingDong | (val ? BitTRUE : BitFALSE); }	//���߱���
	void DefKongJu(bool val = true) { mBitAttr.mBitAttr.d_bKongJu | (val ? BitTRUE : BitFALSE); }	//���߿־�

	bool IsWuDi() { return mBitAttr.mBitAttr.bWudi == BitTRUE; }		//�޵�
	bool IsLianJi() { return mBitAttr.mBitAttr.bLianJi == BitTRUE; } 		//����
	bool IsWuShiFangYu() { return mBitAttr.mBitAttr.bWuShiFangYU == BitTRUE; }	//���ӷ���

	void WuDi(bool val = true) { return mBitAttr.mBitAttr.bWudi | (val ? BitTRUE : BitFALSE); }		//�޵�
	void LianJi(bool val = true) { return mBitAttr.mBitAttr.bLianJi | (val ? BitTRUE : BitFALSE); } 		//����
	void WuShiFangYu(bool val = true) { return mBitAttr.mBitAttr.bWuShiFangYU | (val ? BitTRUE : BitFALSE); }	//���ӷ���

	u32 GetBitValue() { return mBitAttr.mValue; } //��ȡȫ������ֵ
	void SetBitValue(u32 val) { mBitAttr.mValue = val }; //����ȫ������
	//void UpdateValue(u32 val) { mBitAttr.mValue | val }; //���²���ֵ
public:
};