#include "stdafx.h"

map<EIdType, u32> CIdentity::mIds;

u32 CIdentity::NewId(EIdType type) {
	auto it = mIds.find(type);
	if (it == mIds.end()) {
		mIds.insert({ type, 0 });
		return 0;
	}
	u32 ret = ++it->second;
	CIdentity::Save();
	return ret;
}

void CIdentity::Clear(EIdType type) {
	mIds[type] = 0;
	CIdentity::Save();
}

void CIdentity::ClearAll() {
	u8 id = (u8)EIdType::EID_TimerTask;
	u8 max = (u8)EIdType::EID_MaxId;
	for (; id < max; ++id) {
		mIds[(EIdType)id] = 0;
	}
	CIdentity::Save();
}

void CIdentity::Load() {	
	u8 id = (u8)EIdType::EID_TimerTask;
	u8 max = (u8)EIdType::EID_MaxId;
	mIds.clear();
	//如果文件已经存在 读取文件
	ifstream ss(INDEXFILE, ifstream::in | ifstream::binary);	
	if (ss && ss.is_open()) {
		u32 idv = 0;
		for (; id < max; ++id) {
			ss.read(reinterpret_cast<char*>(&idv), sizeof(idv));  //以2进制方式读取
			//ss >> idv; //以text方式读取
			mIds[(EIdType)id] = idv;
		}
		ss.close();
	}
	else {
		//如果文件不存在
		for (; id < max; ++id) {
			mIds[(EIdType)id] = 0;
		}
		//存储
		CIdentity::Save();
	}
}

void CIdentity::Save() {
	//默认已覆盖方式打开
	ofstream ss(INDEXFILE, ofstream::out | ofstream::binary);
	if (ss.is_open()) {
		u8 id = (u8)EIdType::EID_TimerTask;
		u8 max = (u8)EIdType::EID_MaxId;
		//逐个存储
		for (; id < max; ++id) {
			u32 idv = mIds[(EIdType)id];
			//已二进制形式存储
			ss.write(reinterpret_cast<char*>(&idv), sizeof(idv));
		}
		ss.flush();
		ss.close();
	}
	else {
		cerr << "open file " << INDEXFILE << " failed" << endl;
	}
}