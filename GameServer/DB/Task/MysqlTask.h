#pragma once

//全局数据库Id加载
class CLoadIds : public IDBTask {
public:
	CLoadIds();
public:
	void Run() override;
	void Finish() override;
};
//存储timertask
class CSaveTimerTask : public IDBTask {
public:
	CSaveTimerTask();
public:
	void Run() override;
	void Finish() override;
};
//加载timertask
class CLoadTimerTask : public IDBTask {
public:
	CLoadTimerTask();
public:
	void Run() override;
	void Finish() override;
};
//玩家登录前的准备操作
class CPrepareLogin : public IDBTask {
public:
	CPrepareLogin(string& account, u32 serverid, CSession* session);
public:
	void Run() override;
	void Finish() override;
private:
	u32 mServerId{ 0 };			//玩家选择的服务器id
	bool mHasPlayer{ false };	//是否已经创建角色
	u32 mPlayerId{ 0 };		//创建的角色的玩家id
	CSession* mpSession{ nullptr }; //session（客户端）
};
//创建角色
class CCreateRole : public IDBTask {
public:
	CCreateRole(u32 pid, string name, string account, u32 serverid, int platform, CSession* session);
public:
	void Run() override;
	void Finish() override;
private:
	u32 mPid{ 0 };					//创建角色所用的pid
	CSession* mpSession{ nullptr }; //客户端session
	bool mSuccess{ false }; //是否创建成功
};
//加载玩家
class CLoadPlayer : public IDBTask {
public:
	CLoadPlayer(u32 pid, CSession* session);
public:
	void Run() override;
	void Finish() override;
private:
	CPlayer* mpPlayer{ nullptr };  //加载数据的玩家
	bool mSuccess{ false }; //是否成功
};