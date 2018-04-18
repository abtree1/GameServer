#include "stdafx.h"

void SplitString(string source, vector<string>& vec, char sp) {
	//���ַ���ת��Ϊstream
	istringstream input(source);
	//ѭ������ÿ���ָ����ȡ�Ӵ�
	for (string line; getline(input, line, sp);) {
		vec.push_back(line);
	}
}

void SplitString(string source, vector<string>& vec, string sp) {
	string start = "";
	//���ҵ�һ���Ӵ����ֵ�λ��
	for (auto pos = source.find(sp); pos != source.npos;) {
		//��ȡ�Ӵ�ǰ��Ĳ���
		start = source.substr(0, pos);
		vec.push_back(start);
		//��ȡ�Ӵ�����Ĳ���
		source = source.substr(pos + sp.size());
		//������һ���Ӵ����ֵ�λ��
		pos = source.find(sp);
	}
	//ʣ�µĲ���ֱ�Ӽ���
	if (!source.empty())
		vec.push_back(source);
}