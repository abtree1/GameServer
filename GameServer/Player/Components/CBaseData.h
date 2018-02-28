#pragma once

//该类目前主要是演示用法
class CBaseData : public IPlayerData {
public:
	using IPlayerData::IPlayerData;
	CBaseData() = default;
};