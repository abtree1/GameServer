#pragma once

//����һ�������ļ�����������
class ConfigFile {
public:
	map<string, ConfDataBlock>& GetAllCfg() { return mFileData; }
	//��ȡ��������ָ��key�����ÿ�
	ConfDataBlock* GetCfg(int key);
	ConfDataBlock* GetCfg(string& key);
public:
	bool Read(string& filepath);
private:
	//�������ݵ�keyȫͳһΪstring
	map<string, ConfDataBlock> mFileData;
};