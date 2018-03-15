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
	//����ļ��Ѿ����� ��ȡ�ļ�
	ifstream ss(INDEXFILE, ifstream::in | ifstream::binary);	
	if (ss && ss.is_open()) {
		u32 idv = 0;
		for (; id < max; ++id) {
			ss.read(reinterpret_cast<char*>(&idv), sizeof(idv));  //��2���Ʒ�ʽ��ȡ
			//ss >> idv; //��text��ʽ��ȡ
			mIds[(EIdType)id] = idv;
		}
		ss.close();
	}
	else {
		//����ļ�������
		for (; id < max; ++id) {
			mIds[(EIdType)id] = 0;
		}
		//�洢
		CIdentity::Save();
	}
}

void CIdentity::Save() {
	//Ĭ���Ѹ��Ƿ�ʽ��
	ofstream ss(INDEXFILE, ofstream::out | ofstream::binary);
	if (ss.is_open()) {
		u8 id = (u8)EIdType::EID_TimerTask;
		u8 max = (u8)EIdType::EID_MaxId;
		//����洢
		for (; id < max; ++id) {
			u32 idv = mIds[(EIdType)id];
			//�Ѷ�������ʽ�洢
			ss.write(reinterpret_cast<char*>(&idv), sizeof(idv));
		}
		ss.flush();
		ss.close();
	}
	else {
		cerr << "open file " << INDEXFILE << " failed" << endl;
	}
}