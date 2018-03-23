#include "stdafx.h"

//����������ݿ����ʽ
IIdentify* gIdentify = new CIdentityImpl();

u32 CIdentity::NewId(EIdType type) {
	CIdentifyKey key;
	key.set_type(type);
	key.set_ivalue(gConfigMgr->GetSettingValue<INT>(SERVERID));
	string keystr = key.SerializeAsString();
	auto it = mIds.find(keystr);
	if (it == mIds.end()) {
		mIds.insert({ keystr, 0 });
		return 0;
	}
	u32 ret = ++it->second;
	CIdentity::Save();
	return ret;
}

void CIdentity::Clear(EIdType type) {
	CIdentifyKey key;
	key.set_type(type);
	key.set_ivalue(gConfigMgr->GetSettingValue<INT>(SERVERID));
	mIds[key.SerializeAsString()] = 0;
	CIdentity::Save();
}

void CIdentity::ClearAll() {
	for (auto &it : mIds) {
		it.second = 0;
	}
	CIdentity::Save();
}

void CIdentity::Load() {
	mIds.clear();
	
	//����ļ��Ѿ����� ��ȡ�ļ�
	ifstream ss(INDEXFILE, ifstream::in | ifstream::binary);
	if (ss && ss.is_open()) {
		int size = 0;
		u32 idv = 0;
		while (!ss.eof()) {
			ss.read(reinterpret_cast<char*>(&size), sizeof(int));  //��2���Ʒ�ʽ��ȡ
			char buff[256];
			ss.read(buff, size);
			ss.read(reinterpret_cast<char*>(&idv), sizeof(u32));
			mIds[string(buff)] = idv;
		}
		ss.close();
	}
	else {
		//����ļ�������
		CIdentifyKey key;
		u32 serverid = gConfigMgr->GetSettingValue<INT>(SERVERID);
		key.set_type(EID_PlayerId);
		key.set_ivalue(serverid);
		mIds[key.SerializeAsString()] = serverid * PLAYER_MAX_COUNT;
		//�洢
		CIdentity::Save();
	}
}

void CIdentity::Save() {
	//Ĭ���Ѹ��Ƿ�ʽ��
	ofstream ss(INDEXFILE, ofstream::out | ofstream::binary);
	if (ss.is_open()) {
		//����洢
		for (auto it : mIds) {
			//�Ѷ�������ʽ�洢
			int size = it.first.size();
			ss.write(reinterpret_cast<char*>(&size), sizeof(int));
			ss << it.first.c_str();
			ss.write(reinterpret_cast<char*>(&it.second), sizeof(u32));
		}
		ss.flush();
		ss.close();
	}
	else {
		cerr << "open file " << INDEXFILE << " failed" << endl;
	}
}
//########################################################################
u32 CIdentityImpl::NewId(EIdType type) {
	CIdentifyKey key;
	key.set_type(type);
	key.set_ivalue(gConfigMgr->GetSettingValue<INT>(SERVERID));
	string keystr = key.SerializeAsString();
	auto it = mIds.find(keystr);
	if (it == mIds.end()) {
		mIds.insert({ keystr, 0 });
		return 0;
	}
	u32 ret = ++it->second;
	return ret;
}

void CIdentityImpl::Clear(EIdType type) {
	CIdentifyKey key;
	key.set_type(type);
	key.set_ivalue(gConfigMgr->GetSettingValue<INT>(SERVERID));
	mIds[key.SerializeAsString()] = 0;
}

void CIdentityImpl::ClearAll() {
	for (auto &it : mIds) {
		it.second = 0;
	}
}

void CIdentityImpl::Load() {
	CThreadLoad::GetInstance()->AddTask(new CLoadIds());
}

void CIdentityImpl::Save() {
	//Ŀǰ ��û�д洢������
}