#pragma once

//当前类需要将实例传入net库底层 用于底层回调
class CSessionMgr : public CSingleton<CSessionMgr> {
	SINGLETION_FRIEND_CLASS_REGISTER(CSessionMgr)
private:
	CSessionMgr();
	~CSessionMgr();
public:
	//开启网络实例
	void Start(string ip, int port);
	//作为客户端连接server
	int Connect(string ip, int port);
	//注册新的连接
	bool HandleConnect(NetIOCP::ISession* pSession);
	//获取某个session
	CSession* FindSession(int sessionid);
	//关闭已有连接
	bool HandleDisconnect(NetIOCP::ISession* pSession);
	//循环获取新收到的消息
	void Update();
private:
	//保存所有连入的Client Session
	map<int, CSession*> mpSessionVec;
	//保存传入net库的实例对象
	CSessionHandle mpSessionHandle;
	//保存net 库的对象
	NetIOCP::ISessionManager* mpMgr;
};