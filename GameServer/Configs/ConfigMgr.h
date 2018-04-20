#pragma once

class CConfigMgr : public CSingleton<CConfigMgr>, public IConfigMgr {
	SINGLETION_FRIEND_CLASS_REGISTER(CConfigMgr)
protected:
	CConfigMgr();
	virtual ~CConfigMgr();
public:
	//获取Conf的配置文件
	ConfigFile* GetConfFile(string name);
public:
	//处理prop配置文件
	ConfDataBlock* GetPropFile(string name);
	template<typename T>
	T GetPropValue(string name, string title) {
		T t{};  //这里定义变量并设置默认值;
		ConfDataBlock* file = GetPropFile(name);
		if (file == nullptr)
			return t;
		file->GetValue(title, t);
		return t;
	}
	template<typename T>
	T GetSettingValue(string title) {
		return GetPropValue<T>(DEFSETTING, title);
	}
public: //处理 屏蔽字(.dw) 配置文件
	//获取屏蔽字配置文件
	IDWFile* GetDWFile(string name);
	//获取默认屏蔽字配置文件
	IDWFile* GetDefDWFile() { return GetDWFile(DEFDIRTYWORD); }
	//匹配默认屏蔽字配置文件
	INT MatchDWDef(string& source, string& matched);
public:
	//获取多语言配置
	ILanguage* GetLanConf() { return mpLanguage; }
	//获取默认语言配置
	string GetLanDef(INT id) { return mpLanguage->GetDefData(id); }
	string GetLanDef(INT id, string def) { return mpLanguage->GetDefData(id, def); }
public:
	//数据库配置
	CDBConfig& GetDBConf() { return mDBCfg; }
public:
	//处理 .conf 文件
	virtual bool ReadConf(string filename, string fullpath) override;
	//处理 .prop 文件
	virtual bool ReadProp(string filename, string fullpath) override;
	//处理 .dw 文件
	virtual bool ReadDW(string filename, string fullpath) override;
	//处理 .sqls 文件
	virtual bool ReadSqls(string filename, string fullpath) override;
	//处理 .xml 文件 (留给外层自定义处理)
	//virtual bool ReadXml(string filename, string fullpath);
	//处理 .lan 文件
	virtual bool ReadLan(string filename, string fullpath) override;
protected:
	//配置文件名 和 其配置的内容
	map<string, ConfigFile> mConfs;
	//设置类的配置项
	map<string, ConfDataBlock> mProps;
	//屏蔽字文件
	map<string, IDWFile*> mDWFiles;
	//多语言
	ILanguage* mpLanguage{nullptr};
	//数据库配置文件
	CDBConfig mDBCfg;
};

extern CConfigMgr* gConfigMgr;