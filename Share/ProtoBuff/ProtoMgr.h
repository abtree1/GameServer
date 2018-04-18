#pragma once

class CSession;

//该类保存了所有消息处理的函数
class CProtoMgr : public CSingleton<CProtoMgr>, IProto<::google::protobuf::Message, CSession> {
	SINGLETION_FRIEND_CLASS_REGISTER(CProtoMgr)
private:
	CProtoMgr() = default;
	~CProtoMgr() = default;
public:
	bool RegisterProto(UINT type, msg_create create, msg_handle handle) override;
	SMsgHandle* GetProtoHandle(UINT type) override;
};