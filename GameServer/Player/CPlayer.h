#pragma once

class CPlayer {
	CPlayer() = default;
	~CPlayer() = default;
/************************************************************************/
//组件部分
public:
	//获取组件
	CBaseData* GetBaseData() { return &mBaseData; }
private:
	//添加组件
	CBaseData mBaseData{ this };
/************************************************************************/
};
