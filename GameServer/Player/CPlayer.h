#pragma once

class CPlayer {
public:
	CPlayer() = default;
	~CPlayer() = default;
public:
	//��������
	u32 mId{ 0 };			//���id
	string mName{ "" };		//�������
	string mAccount{ "" };	//����ʺ�
	u32 mServerId{ 0 };		//��ҷ�����id���Ϸ��󲻱䣩
	u32 mPlatform{ 0 };		//���ƽ̨���ţ�sdkʹ�ã�
	string mCreateTime{ "" };	//����ʱ��
	string mOnlineTime{ "" };	//���һ������ʱ��
	string mOfflineTime{ "" };	//���һ������ʱ��
public:
	//��չ����
	u32 mLevel{ 0 };	// �ȼ�
	u32 mResId{ 0 };	// ͷ��
	u32 mCoin{ 0 };		// ���
	u32 mExp{ 0 };		// ����
public:
	//����
	CSession* mpSession{ nullptr }; //�ͻ��˵�session
/************************************************************************/
//�������
public:
	//��ȡ���
	CVIPData* GetVipData() { return &mVipData; }
private:
	//������
	CVIPData mVipData{ this };
/************************************************************************/
};
