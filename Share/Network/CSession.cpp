#include "stdafx.h"
using namespace NetIOCP;

CSession::CSession(ISession* session)
	:mpSession(session) {

}

void CSession::Recv() {
	string data = "";
	bool hasData = mpSession->OnRecv(data);
	if (hasData) {
		NetMsgPack msg;
		msg.ParseFromString(data);
		//获取消息处理对象
		//return type => IProto::SMsgHandle*
		//auto handle = CProtoMgr::GetInstance()->GetProtoHandle(msg.type());
		//找到处理该消息的handle类对象
		auto handle = CProtoMgr::GetInstance()->GetProtoHandle(mpSession->GetSessionId());
		if (!handle) {
			printf("msg not find a handle! \n");
			return;
		}
		//在handle类对象中找到处理该消息的对象
		auto phandle = handle->GetProtoHandle(msg.type());
		if (phandle) {
			//return type => ::google::protobuf::Message*
			auto recvMsg = phandle->mFunCreate();
			if (recvMsg) {
				//解析消息参数
				recvMsg->ParseFromString(msg.msg());
			}
			//处理消息
			phandle->mFunHandle(this, recvMsg);
			if (recvMsg)
				delete recvMsg;
		}
	}
}

void CSession::Send(UINT type, ::google::protobuf::Message* msg) {
	string msgstr = "";
	if (msg)  //如果不是空消息 填充消息
		msgstr = msg->SerializeAsString();
	NetMsgPack sendMsg;
	sendMsg.set_type(type);
	sendMsg.set_msg(msgstr);
	mpSession->OnSend(sendMsg.SerializeAsString());
}