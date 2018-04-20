#include "stdafx.h"

//���ǵ�ʱ������ ȫ�ֱ����Ķ�����GameServer��Init��ͳһʵ����
CConfigMgr* gConfigMgr = nullptr;

CConfigMgr::CConfigMgr() {
	//ע�����������ļ����ͺ����ǵĴ�����
	RegisterType(".prop", CLASS_FUNC(IConfigMgr, ReadProp));
}

CConfigMgr::~CConfigMgr() {

}

bool CConfigMgr::ReadProp(string filename, string fullpath) {
	//���������
	ConfDataBlock& block = mProps[filename];
	if (!block.Empty())
		block.Clear();
	//��ȡprop�ļ�
	return DoReadProp(block, fullpath);
}

ConfDataBlock* CConfigMgr::GetPropFile(string name) {
	auto it = mProps.find(name);
	if (it == mProps.end())
		return nullptr;
	return &(it->second);
}