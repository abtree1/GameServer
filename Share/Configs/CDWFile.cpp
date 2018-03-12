#include "stdafx.h"

CDWFile::~CDWFile() {
	//清空数据
	Clear();
}

void CDWFile::Build(string& word) {
	//查询是否已经存在节点
	char c = word[0];
	auto it = mDirtyWords.find(c);
	if (it == mDirtyWords.end()) {
		//注册一个新节点
		DWNode* child = new DWNode();
		mDirtyWords.insert({ c, child });
		//继续子节点的处理
		BuildChild(word, 1, child);
	}
	else {
		//直接处理子节点
		BuildChild(word, 1, it->second);
	}
}

void CDWFile::BuildChild(string& word, int pos, DWNode* node) {
	if (pos >= word.size()) {
		//如果已经到单词尾 标记并返回
		node->isEnd = true;
		return;
	}
	//处理子节点
	char c = word[pos];
	auto it = node->nexts.find(c);
	if (it == node->nexts.end()) {
		//创建一个节点
		DWNode* child = new DWNode();
		//加入node
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
			continue;  //如果找不到该字母 跳到下一个字母检查
		else {
			//从该字母检查是否匹配单词
			int start = i;
			int end = MatchChild(source, i + 1, it->second);
			if (end > start) {
				//匹配到单词 取出匹配到的单词 并返回
				int len = end - start;
				matched = source.substr(start, len);
				return start;
			}
		}
	}
	return -1;
}

INT CDWFile::MatchChild(string& source, int pos, DWNode* node) {
	if (node->isEnd)  //遇见单词结尾 一定是匹配到了单词
		return pos;
	if (pos >= source.size())  //已经匹配到字符串结尾 没有匹配成功
		return -1;
	auto it = node->nexts.find(source[pos]);
	if (it == node->nexts.end())
		return -1;  //匹配的下一个单词不存在 没有匹配成功
	else //继续匹配下一个单词
		return MatchChild(source, pos + 1, it->second);
}

void CDWFile::Clear() {
	//逐项清空
	for (auto it : mDirtyWords) {
		ClearChild(it.second); //清空子节点
		delete it.second;
	}
	mDirtyWords.clear();
}

void CDWFile::ClearChild(DWNode* node) {
	//子节点逐项清空
	for (auto it : node->nexts) {
		ClearChild(it.second);
		delete it.second;
	}
}