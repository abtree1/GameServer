#include "stdafx.h"

//考虑到时序问题 全局变量的定义在GameServer的Init中统一实例化
CConfigMgr* gConfigMgr = nullptr;

CConfigMgr::CConfigMgr() {
	//注册所有配置文件类型和他们的处理函数
	RegisterType(".prop", CLASS_FUNC(IConfigMgr, ReadProp));
}

CConfigMgr::~CConfigMgr() {

}

bool CConfigMgr::ReadProp(string filename, string fullpath) {
	//清空老数据
	ConfDataBlock& block = mProps[filename];
	if (!block.Empty())
		block.Clear();
	//读取prop文件
	return DoReadProp(block, fullpath);
}

ConfDataBlock* CConfigMgr::GetPropFile(string name) {
	auto it = mProps.find(name);
	if (it == mProps.end())
		return nullptr;
	return &(it->second);
}