#pragma once

//������ �ֵ�����ÿһ���ڵ�
class DWNode {
public:
	//�Ƿ�Ϊ��β�ڵ�
	bool isEnd{ false };
	//�ýڵ����һ���ڵ�ļ���
	map<char, DWNode*> nexts;
};

//������ �ֵ���
class IDWFile {
public:
	virtual ~IDWFile() = default;
public:
	//�����ֵ���
	virtual void Build(string& word) = 0;
	//ƥ���ֵ���
	virtual INT Match(string& source, string& matched) = 0;
	//����ֵ���
	virtual void Clear() = 0;
protected:
	//�ֵ���
	map<char, DWNode*> mDirtyWords;
};