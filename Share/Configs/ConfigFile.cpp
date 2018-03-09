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
	//清空老数据
	if (!mFileData.empty())
		mFileData.clear();

	//打开文件
	ifstream ss;
	ss.open(filepath, ifstream::in);
	if (!ss.is_open()) {
		cerr << "Open File Failed " << filepath.c_str() << endl;
		return false;
	}

	//读取标题
	string s;
	vector<pair<string, string>> head;
	while (ss >> s) {
		//先找到配置文件头开始的地方
		if (s == "^")
			break;
	}
	vector<string> vec;
	//读取标题
	while (ss >> s) {
		//结束符
		if (s == "$")
			break;
		vec.clear();
		SplitString(s, vec, ':');
		if (vec.size() == 2) {
			head.push_back(make_pair(vec[0], vec[1]));
		}
	}
	//没有标题行 为空配置
	if (head.empty())
		return false;
	int size = head.size();
	//读取配置内容
	bool ret = true;
	while (ss >> s) {
		if (s != "#")  // == # 表示读取到开始地方了
			continue;

		ConfDataBlock block;
		string key;
		//读取数据
		for (int i = 0; i < size; ++i) {
			string dtype = head[i].second;
			string dname = head[i].first;
			if (dtype == "int") {  //读取int
				int data;
				ss >> data;
				block.SetIntValue(dname, data);
				if (i == 0)
					key = to_string(data);
			}
			else if (dtype == "string") {  //读取string
				ss >> s;
				block.SetStringValue(dname, s);
				if (i == 0)
					key = s;
			}
			else if (dtype == "float") { //读取float
				float data;
				ss >> data;
				block.SetFloatValue(dname, data);
				if (i == 0)
					key = to_string(data);
			}
			else if (dtype == "double") { //读取double
				double data;
				ss >> data;
				block.SetDoubleValue(dname, data);
				if (i == 0)
					key = to_string(data);
			}
			else if (dtype == "char") { //读取char
				char data;
				ss >> data;
				block.SetCharValue(dname, data);
				if (i == 0)
					key = data;
			}
			else if (dtype == "bool") { //读取bool
				bool data;
				ss >> std::boolalpha >> data;
				block.SetBoolValue(dname, data);
				if (i == 0)
					key = to_string(data);
			}
			else {
				//表示配置数据异常
				cerr << "get file title type error " << dtype.c_str() << " in file " << filepath.c_str() << endl;
				ret = false;
				break;
			}
		}
		mFileData[key] = block;
	}
	return ret;
}