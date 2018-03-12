#include "stdafx.h"

void SplitString(string source, vector<string>& vec, char sp) {
	istringstream input(source);
	for (string line; getline(input, line, sp);) {
		vec.push_back(line);
	}
}

void SplitString(string source, vector<string>& vec, string sp) {
	string start = "";
	for (auto pos = source.find(sp); pos != source.npos;) {
		start = source.substr(0, pos);
		vec.push_back(start);
		source = source.substr(pos + sp.size());
		pos = source.find(sp);
	}
	if (!source.empty())
		vec.push_back(source);
}