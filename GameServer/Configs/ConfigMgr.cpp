#include "stdafx.h"

//考虑到时序问题 全局变量的定义在GameServer的Init中统一实例化
CConfigMgr* gConfigMgr = nullptr;

CConfigMgr::CConfigMgr() {
	//注册所有配置文件类型和他们的处理函数
	RegisterType(".conf", CLASS_FUNC(IConfigMgr, ReadConf));
	RegisterType(".prop", CLASS_FUNC(IConfigMgr, ReadProp));
	RegisterType(".dw", CLASS_FUNC(IConfigMgr, ReadDW));
	RegisterType(".sqls", CLASS_FUNC(IConfigMgr, ReadSqls));
	RegisterType(".xml", nullptr); //该类型不注册处理函数
	RegisterType(".lan", CLASS_FUNC(IConfigMgr, ReadLan));
}

CConfigMgr::~CConfigMgr() {
	//屏蔽字
	for (auto itDwFile : mDWFiles) {
		if (itDwFile.second) {
			itDwFile.second->Clear();
			delete itDwFile.second;
		}
	}
	mDWFiles.clear();
	//多语言
	if (mpLanguage)
		delete mpLanguage;
}

bool CConfigMgr::ReadConf(string filename, string fullpath) {
	ConfigFile& file = mConfs[filename];
	return file.Read(fullpath);
}

bool CConfigMgr::ReadProp(string filename, string fullpath) {
	//清空老数据
	ConfDataBlock& block = mProps[filename];
	if (!block.Empty())
		block.Clear();
	//读取prop文件
	return DoReadProp(block, fullpath);
}

bool CConfigMgr::ReadDW(string filename, string fullpath) {
	IDWFile* file = nullptr;
	auto it = mDWFiles.find(filename);
	if (it != mDWFiles.end()) {
		if (it->second) {
			file = it->second;
			file->Clear();  //清空老数据
		}
		else {
			//删除原来的
			mDWFiles.erase(filename);
			//新建一个屏蔽字文件
			file = new CDWFile();
			mDWFiles.insert({ filename, file });
		}
	}
	else {
		//新建一个屏蔽字文件
		file = new CDWFile();
		mDWFiles.insert({ filename, file });
	}
	
	//打开文件
	ifstream ss;
	ss.open(fullpath, ifstream::in);
	if (!ss.is_open()) {
		cerr << "Open File Failed " << filename.c_str() << endl;
		delete file;
		return false;
	}
	string word;
	//读取屏蔽字文件
	while (ss >> word) {
		file->Build(word);
	}
	ss.close();
	return true;
}

bool CConfigMgr::ReadSqls(string filename, string fullpath) {
	return mDBCfg.Read(fullpath);
}

//bool IConfigMgr::ReadXml(string filename, string fullpath) {
//	return true;
//}

bool CConfigMgr::ReadLan(string filename, string fullpath) {
	if (!mpLanguage) {
		//初始化 并设置默认语言
		mpLanguage = new CLanguage(DEFLANGUAGE);
	}
	//读取配置
	return mpLanguage->Read(fullpath);
}

ConfigFile* CConfigMgr::GetConfFile(string name) {
	auto it = mConfs.find(name);
	if (it == mConfs.end())
		return nullptr;
	return &(it->second);
}

ConfDataBlock* CConfigMgr::GetPropFile(string name) {
	auto it = mProps.find(name);
	if (it == mProps.end())
		return nullptr;
	return &(it->second);
}

IDWFile* CConfigMgr::GetDWFile(string name) {
	auto it = mDWFiles.find(name);
	if (it == mDWFiles.end())
		return nullptr;
	return it->second;
}

INT CConfigMgr::MatchDWDef(string& source, string& matched) {
	IDWFile* file = GetDefDWFile();
	if (file) {
		return file->Match(source, matched);
	}
	return -1; //匹配失败
}