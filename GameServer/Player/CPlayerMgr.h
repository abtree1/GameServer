#pragma once

class CPlayerMgr :public CSingleton<CPlayerMgr> {
	SINGLETION_FRIEND_CLASS_REGISTER(CPlayerMgr)
private:
	CPlayerMgr() = default;
	~CPlayerMgr() = default;
private:
	//玩家帐号与ID对应表
	map<string, UINT> mPlayerAccountToId;
	//所有加载的玩家
	map<UINT, CPlayer*> mAllPlayers;
public:
	//通过玩家帐号获取玩家 后期考虑合服需求 该函数还需要变动
	CPlayer* GetPlayerByAccount(string &account);
	void RegisterPlayer(CPlayer* player);
};
