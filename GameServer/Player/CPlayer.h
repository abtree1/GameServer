#pragma once

class CPlayer {
	CPlayer() = default;
	~CPlayer() = default;
/************************************************************************/
//�������
public:
	//��ȡ���
	CBaseData* GetBaseData() { return &mBaseData; }
private:
	//������
	CBaseData mBaseData{ this };
/************************************************************************/
};
