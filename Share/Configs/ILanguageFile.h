#pragma once

class ILanguage {
public:
	ILanguage(string lan) :mLanguage(lan) {}
public:
	//设置所使用的语言
	void SetLan(string lan) { mLanguage = lan; }
	//获取设置的语言
	string &GetLan() { return mLanguage; }
public:
	//读取语言配置
	virtual bool Read(string filepath) = 0;
public:
	//获取设置的语言的数据
	virtual map<INT, string>* GetDefLanguageData() { return GetLanguageData(mLanguage); }
	//获取指定语言的数据
	virtual map<INT, string>* GetLanguageData(string& lan);
	//获取 默认语言的 配置数据
	virtual string GetDefData(INT id) { return GetData(id, mLanguage); }
	//如果获取失败 就返回默认值
	virtual string GetDefData(INT id, string def);
	//获取指定语言的配置项数据
	virtual string GetData(INT id, string& lan);
protected:
	//设置默认使用的语言
	string mLanguage{ "" };
	//不同语言的配置数据
	map<string, map<INT, string>> mDatas;
};