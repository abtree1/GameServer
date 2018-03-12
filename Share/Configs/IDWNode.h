#pragma once

//屏蔽字 字典树的每一个节点
class DWNode {
public:
	//是否为结尾节点
	bool isEnd{ false };
	//该节点的下一个节点的集合
	map<char, DWNode*> nexts;
};

//屏蔽字 字典树
class IDWFile {
public:
	virtual ~IDWFile() = default;
public:
	//构建字典树
	virtual void Build(string& word) = 0;
	//匹配字典树
	virtual INT Match(string& source, string& matched) = 0;
	//清空字典树
	virtual void Clear() = 0;
protected:
	//字典树
	map<char, DWNode*> mDirtyWords;
};