#include "stdafx.h"

CPlayer* CPlayerMgr::GetPlayerByAccount(string &account) {
	auto itid = mPlayerAccountToId.find(account);
	if (itid == mPlayerAccountToId.end())
		return nullptr;
	auto itp = mAllPlayers.find(itid->second);
	if (itp == mAllPlayers.end())
		return nullptr;
	return itp->second;
}

void CPlayerMgr::RegisterPlayer(CPlayer* player) {
	mPlayerAccountToId[player->mAccount] = player->mId;
	mAllPlayers[player->mId] = player;
	//给玩家发送加载完成消息
}