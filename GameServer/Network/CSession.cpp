#include "stdafx.h"
using namespace NetIOCP;

CSession::CSession(ISession* session)
	:mpSession(session) {

}

void CSession::Recv() {
	string data = "";
	bool hasData = mpSession->OnRecv(data);
	if (hasData) {
		//printf("recv data: %s \n", data.c_str());
		//mpSession->OnSend(data);
		NetMsgPack msg;
		msg.ParseFromString(data);
		//��ȡ��Ϣ�������
		//return type => IProto::SMsgHandle*
		auto handle = CProtoMgr::GetInstance()->GetProtoHandle(msg.type());
		if (handle) {
			//return type => ::google::protobuf::Message*
			auto recvMsg = handle->mFunCreate();
			if (recvMsg) {
				//������Ϣ����
				recvMsg->ParseFromString(msg.msg());
			}
			//������Ϣ
			handle->mFunHandle(this, recvMsg);
			if (recvMsg)
				delete recvMsg;
		}
	}
}

void CSession::Send(UINT type, ::google::protobuf::Message* msg) {
	if (!msg)
		return;
	NetMsgPack sendMsg;
	sendMsg.set_type(type);
	sendMsg.set_msg(msg->SerializeAsString());
	//sendMsg.set_code("");
	mpSession->OnSend(sendMsg.SerializeAsString());
}