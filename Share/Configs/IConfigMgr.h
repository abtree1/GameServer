#pragma once
class IConfigMgr;
using ClassFunc = bool (IConfigMgr::*)(string, string);

class IConfigMgr : public CSingleton<IConfigMgr> {
	SINGLETION_FRIEND_CLASS_REGISTER(IConfigMgr)
protected:
	IConfigMgr();
	virtual ~IConfigMgr() = default;
public:
	//指定类型的配置文件是否注册
	bool IsRegisterType(string& type);
	//注册配置文件类型
	bool RegisterType(string type, ClassFunc func);
public:
	//读取配置文件
	bool Read(string basePath);
public:
	//获取Conf的配置文件
	ConfigFile* GetConfFile(string name);
protected:
	//获取目录下的所有配置文件路径(含子文件夹文件)
	bool ReadFilePath(boost::filesystem::path& fullpath, string filehead);
public:
	//处理 .conf 文件
	virtual bool ReadConf(string filename, string fullpath);
	//处理 .prop 文件
	virtual bool ReadProp(string filename, string fullpath);
	//处理 .dw 文件
	virtual bool ReadDW(string filename, string fullpath);
	//处理 .sqls 文件
	virtual bool ReadSqls(string filename, string fullpath);
	//处理 .xml 文件
	virtual bool ReadXml(string filename, string fullpath);
	//处理 .lan 文件
	virtual bool ReadLan(string filename, string fullpath);
protected:
	//保存文件和对应的路径
	map<string, boost::filesystem::path> mFilePaths;
	//配置文件名 和 其配置的内容
	map<string, ConfigFile> mConfs;
	//注册的配置文件类型
	map<string, ClassFunc> mTypes;
};