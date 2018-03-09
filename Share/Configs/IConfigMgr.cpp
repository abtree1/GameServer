#include "stdafx.h"

typedef boost::filesystem::path Path;

IConfigMgr::IConfigMgr() {
	//ע�����������ļ����ͺ����ǵĴ�������
	RegisterType(".conf", CLASS_FUNC(IConfigMgr, ReadConf));
	RegisterType(".prop", CLASS_FUNC(IConfigMgr, ReadProp));
	RegisterType(".dw", CLASS_FUNC(IConfigMgr, ReadDW));
	RegisterType(".sqls", CLASS_FUNC(IConfigMgr, ReadSqls));
	RegisterType(".xml", CLASS_FUNC(IConfigMgr, ReadXml));
	RegisterType(".lan", CLASS_FUNC(IConfigMgr, ReadLan));
}

bool IConfigMgr::IsRegisterType(string& type) {
	return (mTypes.find(type) != mTypes.end());
}

bool IConfigMgr::RegisterType(string type, ClassFunc func) {
	if (IsRegisterType(type))
		return false;
	mTypes[type] = func;
	return true;
}

bool IConfigMgr::Read(string basePath) {
	//���·���Ƿ�Ϸ�
	Path fullpath(basePath, boost::filesystem::native);
	if (!boost::filesystem::exists(fullpath)) {
		printf("%s, is not a real path", basePath.c_str());
		return false;
	}
	//��ȡ���е������ļ���·��
	if (!ReadFilePath(fullpath, "")) {
		printf("read all config file pathes error");
		return false;
	}
	//��ȡÿ��ע�����͵������ļ�������
	for (auto &itpath : mFilePaths) {
		auto ittype = mTypes.find(itpath.second.extension().string());
		if(ittype == mTypes.end())
			continue;   //��ע�����͵��ļ�
		//��ȡ���ļ�
		bool ret = (this->*(ittype->second))(itpath.first, itpath.second.string());
		if (!ret)
			return false;
	}
	return true;
}

//��ȡ·���£�������·���������ļ�
bool IConfigMgr::ReadFilePath(boost::filesystem::path& fullpath, string filehead) {
	try {
		//����·��
		boost::filesystem::recursive_directory_iterator end_iter;
		for (boost::filesystem::recursive_directory_iterator iter(fullpath); iter != end_iter; iter++) {
			Path pat = iter->path();
			//����ļ����Ƿ���('.')��ʼ ����Ϊ��Ч�ļ� 
			if (pat.stem().empty() || pat.stem().string()[0] == '.')
				continue;
			//������ļ���
			if (boost::filesystem::is_directory(*iter)) {
				//��ȡ�ļ������ļ�
				if (!ReadFilePath(pat, filehead + pat.stem().string() + "/"))
					return false;  //�����ȡ�쳣 ����false
			}
			else {
				//�������ע��������ļ����� ��������
				string ext = pat.extension().string();
				if (mTypes.find(ext) == mTypes.end())
					continue;
				//�����ļ�·��
				string filename = filehead + pat.stem().string();
				mFilePaths[filename] = pat;
			}
		}
	}
	catch (const std::exception & ex) {
		std::cerr << ex.what() << std::endl;
		return false;
	}
	return true;
}

bool IConfigMgr::ReadConf(string filename, string fullpath) {
	ConfigFile& file = mConfs[filename];
	return file.Read(fullpath);
}

bool IConfigMgr::ReadProp(string filename, string fullpath) {
	return true;
}

bool IConfigMgr::ReadDW(string filename, string fullpath) {
	return true;
}

bool IConfigMgr::ReadSqls(string filename, string fullpath) {
	return true;
}

bool IConfigMgr::ReadXml(string filename, string fullpath) {
	return true;
}

bool IConfigMgr::ReadLan(string filename, string fullpath) {
	return true;
}

ConfigFile* IConfigMgr::GetConfFile(string name) {
	auto it = mConfs.find(name);
	if (it == mConfs.end())
		return nullptr;
	return &(it->second);
}