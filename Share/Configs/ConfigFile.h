#pragma once

//保存一个配置文件的配置数据
class ConfigFile {
public:
	map<string, ConfDataBlock>& GetAllCfg() { return mFileData; }
	//获取配置项中指定key的配置块
	ConfDataBlock* GetCfg(int key);
	ConfDataBlock* GetCfg(string& key);
public:
	bool Read(string& filepath);
private:
	//配置数据的key全统一为string
	map<string, ConfDataBlock> mFileData;
};