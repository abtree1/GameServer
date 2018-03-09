#include "stdafx.h"

void SplitString(string source, vector<string>& vec, char sp) {
	istringstream input(source);
	for (string line; getline(input, line, sp);) {
		vec.push_back(line);
	}
}