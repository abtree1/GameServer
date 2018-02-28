#pragma once
class CPlayer;

//该类 为Player的组件的基类
/*
	在实际开发过程中 常常照成Player过大而难于维护
	此处加入Player的组件 目的就是将Player中相对独立的
	内容包装为组件加入Player中 以保持Player不会膨胀
*/
class IPlayerData {
public:
	IPlayerData(CPlayer* player) :mpPlayer(player) {}
	~IPlayerData() = default;
protected:
	CPlayer* mpPlayer; //data 组件所属的Player(每个组件实例都属于某个Player)
};