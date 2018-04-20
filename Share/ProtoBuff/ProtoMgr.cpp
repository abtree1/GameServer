#include "stdafx.h"

bool CProtoMgr::RegisterHandle(s32 id, IMsgHandle* handle) {
	if (!handle)
		return false;
	mRegisterMsgHandles[id] = handle;
	return true;
}

bool CProtoMgr::RegisterDefHandle(IMsgHandle* handle) {
	if (!handle)
		return false;
	mDefaultMsgHandle = handle;
	return true;
}

IMsgHandle* CProtoMgr::GetProtoHandle(s32 id) {
	auto it = mRegisterMsgHandles.find(id);
	if (it == mRegisterMsgHandles.end())
		return mDefaultMsgHandle;
	return it->second;
}