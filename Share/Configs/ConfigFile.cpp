#include "stdafx.h"

ConfDataBlock* ConfigFile::GetCfg(int key) {
	return GetCfg(to_string(key));
}

ConfDataBlock* ConfigFile::GetCfg(string& key) {
	auto it = mFileData.find(key);
	if (it == mFileData.end())
		return nullptr;
	return &(it->second);
}

bool ConfigFile::Read(string& filepath) {
	//���������
	if (!mFileData.empty())
		mFileData.clear();

	//���ļ�
	ifstream ss;
	ss.open(filepath, ifstream::in);
	if (!ss.is_open()) {
		cerr << "Open File Failed " << filepath.c_str() << endl;
		return false;
	}

	//��ȡ����
	string s;
	vector<pair<string, string>> head;
	while (ss >> s) {
		//���ҵ������ļ�ͷ��ʼ�ĵط�
		if (s == "^")
			break;
	}
	vector<string> vec;
	//��ȡ����
	while (ss >> s) {
		//������
		if (s == "$")
			break;
		vec.clear();
		SplitString(s, vec, ':');
		if (vec.size() == 2) {
			head.push_back(make_pair(vec[0], vec[1]));
		}
	}
	//û�б����� Ϊ������
	if (head.empty())
		return false;
	int size = head.size();
	//��ȡ��������
	bool ret = true;
	while (ss >> s) {
		if (s != "#")  // == # ��ʾ��ȡ����ʼ�ط���
			continue;

		ConfDataBlock block;
		string key;
		//��ȡ����
		for (int i = 0; i < size; ++i) {
			string dtype = head[i].second;
			string dname = head[i].first;
			if (dtype == "int") {  //��ȡint
				int data;
				ss >> data;
				block.SetIntValue(dname, data);
				if (i == 0)
					key = to_string(data);
			}
			else if (dtype == "string") {  //��ȡstring
				ss >> s;
				block.SetStringValue(dname, s);
				if (i == 0)
					key = s;
			}
			else if (dtype == "float") { //��ȡfloat
				float data;
				ss >> data;
				block.SetFloatValue(dname, data);
				if (i == 0)
					key = to_string(data);
			}
			else if (dtype == "double") { //��ȡdouble
				double data;
				ss >> data;
				block.SetDoubleValue(dname, data);
				if (i == 0)
					key = to_string(data);
			}
			else if (dtype == "char") { //��ȡchar
				char data;
				ss >> data;
				block.SetCharValue(dname, data);
				if (i == 0)
					key = data;
			}
			else if (dtype == "bool") { //��ȡbool
				bool data;
				ss >> std::boolalpha >> data;
				block.SetBoolValue(dname, data);
				if (i == 0)
					key = to_string(data);
			}
			else {
				//��ʾ���������쳣
				cerr << "get file title type error " << dtype.c_str() << " in file " << filepath.c_str() << endl;
				ret = false;
				break;
			}
		}
		mFileData[key] = block;
	}
	return ret;
}