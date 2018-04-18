#include "stdafx.h"

void SplitString(string source, vector<string>& vec, char sp) {
	//将字符串转换为stream
	istringstream input(source);
	//循环根据每个分割符读取子串
	for (string line; getline(input, line, sp);) {
		vec.push_back(line);
	}
}

void SplitString(string source, vector<string>& vec, string sp) {
	string start = "";
	//查找第一个子串出现的位置
	for (auto pos = source.find(sp); pos != source.npos;) {
		//截取子串前面的部分
		start = source.substr(0, pos);
		vec.push_back(start);
		//截取子串后面的部分
		source = source.substr(pos + sp.size());
		//查找下一个子串出现的位置
		pos = source.find(sp);
	}
	//剩下的部分直接加入
	if (!source.empty())
		vec.push_back(source);
}