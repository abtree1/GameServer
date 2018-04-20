#pragma once

class CSession;

//该类保存了所有消息处理的函数
class CProtoMgr : public CSingleton<CProtoMgr>, public IProto{
	SINGLETION_FRIEND_CLASS_REGISTER(CProtoMgr)
private:
	CProtoMgr() = default;
	~CProtoMgr() = default;
public:
	bool RegisterHandle(s32 id, IMsgHandle* handle) override;
	bool RegisterDefHandle(IMsgHandle* handle) override;
	IMsgHandle* GetProtoHandle(s32 id) override;
};