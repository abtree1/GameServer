#include "stdafx.h"

bool CDBConfig::Read(string filepath) {
	//打开文件
	ifstream ss(filepath, ios::in | ios::ate);
	if (!ss.is_open()) {
		cerr << "Open File Failed " << filepath.c_str() << endl;
		return false;
	}
	// read entire file into string
	auto size = ss.tellg();
	std::string file(size, '\0'); // construct string to stream size
	ss.seekg(0);
	ss.read(&file[0], size);
	ss.close();
	if (file.empty()) {
		cerr << "Read File Failed " << filepath.c_str() << endl;
		return false;
	}
	//清空老数据
	mDBMerge.clear();
	//填充新数据
	vector<string> pai;
	SplitString(file, pai, "\t#\t");
	int id = 0;
	size = pai.size();
	for (int i = 0; i < size; ++i) {
		id = atoi(pai[i].c_str());
		if (id <= 0) {
			cerr << "read comfig \"" << filepath.c_str()
				<< " \" with id \"" << pai[i] << " \" error"
				<< endl;
			++i;  //这里需要跳过他的 value 项
			return false;
		}
		++i;
		if (i < size) {
			//添加数据
			mDBMerge.insert({ id, pai[i] });
		}
	}
	return true;
}