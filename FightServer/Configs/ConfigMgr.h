#pragma once

class CConfigMgr : public CSingleton<CConfigMgr>, public IConfigMgr {
	SINGLETION_FRIEND_CLASS_REGISTER(CConfigMgr)
protected:
	CConfigMgr();
	virtual ~CConfigMgr();
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
public:
	//处理 .prop 文件
	virtual bool ReadProp(string filename, string fullpath) override;
protected:
	//设置类的配置项
	map<string, ConfDataBlock> mProps;
};

extern CConfigMgr* gConfigMgr;