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
		//��ȡ��Ϣ�������
		//return type => IProto::SMsgHandle*
		//auto handle = CProtoMgr::GetInstance()->GetProtoHandle(msg.type());
		//�ҵ��������Ϣ��handle�����
		auto handle = CProtoMgr::GetInstance()->GetProtoHandle(mpSession->GetSessionId());
		if (!handle) {
			printf("msg not find a handle! \n");
			return;
		}
		//��handle��������ҵ��������Ϣ�Ķ���
		auto phandle = handle->GetProtoHandle(msg.type());
		if (phandle) {
			//return type => ::google::protobuf::Message*
			auto recvMsg = phandle->mFunCreate();
			if (recvMsg) {
				//������Ϣ����
				recvMsg->ParseFromString(msg.msg());
			}
			//������Ϣ
			phandle->mFunHandle(this, recvMsg);
			if (recvMsg)
				delete recvMsg;
		}
	}
}

void CSession::Send(UINT type, ::google::protobuf::Message* msg) {
	string msgstr = "";
	if (msg)  //������ǿ���Ϣ �����Ϣ
		msgstr = msg->SerializeAsString();
	NetMsgPack sendMsg;
	sendMsg.set_type(type);
	sendMsg.set_msg(msgstr);
	mpSession->OnSend(sendMsg.SerializeAsString());
}