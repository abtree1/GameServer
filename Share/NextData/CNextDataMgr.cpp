#include "stdafx.h"

CNextDataMgr::~CNextDataMgr(){
	for(auto it = mTemps.begin(); it != mTemps.end(); ++it){
		if(it->second)
			delete it->second;
	}
}

CNextData* CNextDataMgr::createTemp(CSPNextData& data){
	string key = data.SerializeAsString();
	//先清理老数据
	auto it = mTemps.find(key);
	if (it != mTemps.end()) {
		delete it->second;
		mTemps.erase(it);
	}
	//注册新事件
	CNextData *pData = new CNextData();
	mTemps[key] = pData;
	return pData;
}

CNextData* CNextDataMgr::findTemp(CSPNextData& data) {
	string key = data.SerializeAsString();
	auto it = mTemps.find(key);
	if (it == mTemps.end()) {
		return nullptr;
	}
	return it->second;
}

void CNextDataMgr::dirtyHandleTemp(CSPNextData& data){
	string key = data.SerializeAsString();
	auto it = mTemps.find(key);
	if (it == mTemps.end()) {
		return;
	}
	if (it->second) {
		it->second->dirtyHandle();
		delete it->second;
	}
	mTemps.erase(it);
}