#include "stdafx.h"

typedef boost::filesystem::path Path;

bool IConfigMgr::IsRegisterType(string& type) {
	return (mTypes.find(type) != mTypes.end());
}

bool IConfigMgr::RegisterType(string type, ThisFunc func) {
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
		if(!ittype->second)  //ע�������� ��ûע�ᴦ����
			continue;
		//��ȡ���ļ�
		bool ret = (this->*(ittype->second))(itpath.first, itpath.second.string());
		if (!ret)
			return false;
	}
	return true;
}

boost::filesystem::path* IConfigMgr::GetFilePath(string filename) {
	auto it = mFilePaths.find(filename);
	if (it == mFilePaths.end())
		return nullptr;
	return &(it->second);
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

bool IConfigMgr::DoReadProp(ConfDataBlock& block, string fullpath) {
	//���ļ�
	ifstream ss;
	ss.open(fullpath, ifstream::in);
	if (!ss.is_open()) {
		cerr << "Open File Failed " << fullpath.c_str() << endl;
		return false;
	}
	string s;
	vector<string> head;
	//��ȡ�� # �Ŵ�
	while (ss >> s) {
		if (s != "#")
			continue;

		//��ȡ����
		ss >> s >> s;
		head.clear();
		SplitString(s, head, ':');
		if (head.size() != 2)
		{
			cerr << "read title fail " << s.c_str() << endl;
			return 0;
		}
		//��ȡ����
		if (head[1] == "int") {
			int i;
			ss >> i;
			block.SetIntValue(head[0], i);
		}
		else if (head[1] == "string") {
			ss >> s;
			block.SetStringValue(head[0], s);
		}
		else if (head[1] == "float") {
			float f;
			ss >> f;
			block.SetFloatValue(head[0], f);
		}
		else if (head[1] == "double") {
			double d;
			ss >> d;
			block.SetDoubleValue(head[0], d);
		}
		else if (head[1] == "char") {
			char c;
			ss >> c;
			block.SetCharValue(head[0], c);
		}
		else if (head[1] == "bool") {
			bool b;
			ss >> std::boolalpha >> b;
			block.SetBoolValue(head[0], b);
		}
		else {
			//��ʾ����type �쳣
			cerr << "read title type fail " << head[1].c_str() << endl;
			ss.close();
			return false;
		}
	}
	ss.close();
	return true;
}