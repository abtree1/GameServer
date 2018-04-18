#include "stdafx.h"

bool CProtoMgr::RegisterProto(UINT type, msg_create create, msg_handle handle) {
	shared_ptr<SMsgHandle> hand = make_shared<SMsgHandle>();
	hand->mFunCreate = create;
	hand->mFunHandle = handle;
	mMsgHandles[type] = hand;
	return true;
}

IProto<::google::protobuf::Message, CSession>::SMsgHandle* CProtoMgr::GetProtoHandle(UINT type) {
	auto it = mMsgHandles.find(type);
	if (it != mMsgHandles.end()) {
		if (it->second)
			return it->second.get();
	}
	return nullptr;
}