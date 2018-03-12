#include "stdafx.h"

CDWFile::~CDWFile() {
	//�������
	Clear();
}

void CDWFile::Build(string& word) {
	//��ѯ�Ƿ��Ѿ����ڽڵ�
	char c = word[0];
	auto it = mDirtyWords.find(c);
	if (it == mDirtyWords.end()) {
		//ע��һ���½ڵ�
		DWNode* child = new DWNode();
		mDirtyWords.insert({ c, child });
		//�����ӽڵ�Ĵ���
		BuildChild(word, 1, child);
	}
	else {
		//ֱ�Ӵ����ӽڵ�
		BuildChild(word, 1, it->second);
	}
}

void CDWFile::BuildChild(string& word, int pos, DWNode* node) {
	if (pos >= word.size()) {
		//����Ѿ�������β ��ǲ�����
		node->isEnd = true;
		return;
	}
	//�����ӽڵ�
	char c = word[pos];
	auto it = node->nexts.find(c);
	if (it == node->nexts.end()) {
		//����һ���ڵ�
		DWNode* child = new DWNode();
		//����node
		node->nexts.insert({ c, child });
		BuildChild(word, ++pos, child);
	}
	else {
		BuildChild(word, ++pos, it->second);
	}
}

INT CDWFile::Match(string& source, string& matched) {
	for (int i = 0; i < source.size(); ++i) {
		char c = source[i];
		auto it = mDirtyWords.find(c);
		if (it == mDirtyWords.end())
			continue;  //����Ҳ�������ĸ ������һ����ĸ���
		else {
			//�Ӹ���ĸ����Ƿ�ƥ�䵥��
			int start = i;
			int end = MatchChild(source, i + 1, it->second);
			if (end > start) {
				//ƥ�䵽���� ȡ��ƥ�䵽�ĵ��� ������
				int len = end - start;
				matched = source.substr(start, len);
				return start;
			}
		}
	}
	return -1;
}

INT CDWFile::MatchChild(string& source, int pos, DWNode* node) {
	if (node->isEnd)  //�������ʽ�β һ����ƥ�䵽�˵���
		return pos;
	if (pos >= source.size())  //�Ѿ�ƥ�䵽�ַ�����β û��ƥ��ɹ�
		return -1;
	auto it = node->nexts.find(source[pos]);
	if (it == node->nexts.end())
		return -1;  //ƥ�����һ�����ʲ����� û��ƥ��ɹ�
	else //����ƥ����һ������
		return MatchChild(source, pos + 1, it->second);
}

void CDWFile::Clear() {
	//�������
	for (auto it : mDirtyWords) {
		ClearChild(it.second); //����ӽڵ�
		delete it.second;
	}
	mDirtyWords.clear();
}

void CDWFile::ClearChild(DWNode* node) {
	//�ӽڵ��������
	for (auto it : node->nexts) {
		ClearChild(it.second);
		delete it.second;
	}
}