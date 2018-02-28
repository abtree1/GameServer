#pragma once

class CPlayerMgr :public CSingleton<CPlayerMgr> {
	SINGLETION_FRIEND_CLASS_REGISTER(CPlayerMgr)
private:
	CPlayerMgr() = default;
	~CPlayerMgr() = default;
private:
	//����ʺ���ID��Ӧ��
	map<string, UINT> mPlayerAccountToId;
	//���м��ص����
	map<UINT, CPlayer*> mAllPlayers;
};
