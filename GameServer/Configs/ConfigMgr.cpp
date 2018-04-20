#include "stdafx.h"

//���ǵ�ʱ������ ȫ�ֱ����Ķ�����GameServer��Init��ͳһʵ����
CConfigMgr* gConfigMgr = nullptr;

CConfigMgr::CConfigMgr() {
	//ע�����������ļ����ͺ����ǵĴ�����
	RegisterType(".conf", CLASS_FUNC(IConfigMgr, ReadConf));
	RegisterType(".prop", CLASS_FUNC(IConfigMgr, ReadProp));
	RegisterType(".dw", CLASS_FUNC(IConfigMgr, ReadDW));
	RegisterType(".sqls", CLASS_FUNC(IConfigMgr, ReadSqls));
	RegisterType(".xml", nullptr); //�����Ͳ�ע�ᴦ����
	RegisterType(".lan", CLASS_FUNC(IConfigMgr, ReadLan));
}

CConfigMgr::~CConfigMgr() {
	//������
	for (auto itDwFile : mDWFiles) {
		if (itDwFile.second) {
			itDwFile.second->Clear();
			delete itDwFile.second;
		}
	}
	mDWFiles.clear();
	//������
	if (mpLanguage)
		delete mpLanguage;
}

bool CConfigMgr::ReadConf(string filename, string fullpath) {
	ConfigFile& file = mConfs[filename];
	return file.Read(fullpath);
}

bool CConfigMgr::ReadProp(string filename, string fullpath) {
	//���������
	ConfDataBlock& block = mProps[filename];
	if (!block.Empty())
		block.Clear();
	//��ȡprop�ļ�
	return DoReadProp(block, fullpath);
}

bool CConfigMgr::ReadDW(string filename, string fullpath) {
	IDWFile* file = nullptr;
	auto it = mDWFiles.find(filename);
	if (it != mDWFiles.end()) {
		if (it->second) {
			file = it->second;
			file->Clear();  //���������
		}
		else {
			//ɾ��ԭ����
			mDWFiles.erase(filename);
			//�½�һ���������ļ�
			file = new CDWFile();
			mDWFiles.insert({ filename, file });
		}
	}
	else {
		//�½�һ���������ļ�
		file = new CDWFile();
		mDWFiles.insert({ filename, file });
	}
	
	//���ļ�
	ifstream ss;
	ss.open(fullpath, ifstream::in);
	if (!ss.is_open()) {
		cerr << "Open File Failed " << filename.c_str() << endl;
		delete file;
		return false;
	}
	string word;
	//��ȡ�������ļ�
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
		//��ʼ�� ������Ĭ������
		mpLanguage = new CLanguage(DEFLANGUAGE);
	}
	//��ȡ����
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
	return -1; //ƥ��ʧ��
}