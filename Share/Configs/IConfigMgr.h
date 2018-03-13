#pragma once
class IConfigMgr;
using ThisFunc = bool (IConfigMgr::*)(string, string);
template<typename T>
using ReadFunc = bool (T::*)(ifstream&);

class IConfigMgr : public CSingleton<IConfigMgr> {
	SINGLETION_FRIEND_CLASS_REGISTER(IConfigMgr)
protected:
	IConfigMgr();
	virtual ~IConfigMgr();
public:
	//指定类型的配置文件是否注册
	bool IsRegisterType(string& type);
	//注册配置文件类型
	bool RegisterType(string type, ThisFunc func);
public:
	//读取配置文件
	bool Read(string basePath);
	//获取文件路径 用于外部读取
	boost::filesystem::path* GetFilePath(string filename);
	//自定义读取文件
	template<typename T>
	bool ReadFile(string filename, T* CA, ReadFunc<T> func, bool isTail = false) {
		//获取文件路径
		auto it = mFilePaths.find(filename);
		if (it == mFilePaths.end()) {
			cerr << "file not find " << filename.c_str() << endl;
			return false;
		}
		//读取配置
		ifstream ss;
		if(isTail)
			ss.open(it->second.string(), ifstream::in | ifstream::ate);
		else
			ss.open(it->second.string(), ifstream::in);
		if (!ss.is_open()) {
			cerr << "Open File Failed " << filename.c_str()
				<< " " << it->second.string().c_str() << endl;
			return false;
		}
		bool ret = (CA->*func)(ss);
		ss.close();
		return ret;
	}
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
		return GetPropValue<T>("Setting", title);
	}
public: //处理 屏蔽字(.dw) 配置文件
	//获取屏蔽字配置文件
	IDWFile* GetDWFile(string name);
	//获取默认屏蔽字配置文件
	IDWFile* GetDefDWFile() { return GetDWFile("dirtyword"); }
	//匹配默认屏蔽字配置文件
	INT MatchDWDef(string& source, string& matched);
public:
	//获取屏蔽字配置
	ILanguage* GetLanConf() { return mpLanguage; }
	//获取默认语言配置
	string GetLanDef(INT id) { return mpLanguage->GetDefData(id); }
	string GetLanDef(INT id, string def) { return mpLanguage->GetDefData(id, def); }
public:
	//数据库配置
	CDBConfig& GetDBConf() { return mDBCfg; }
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
	//处理 .xml 文件 (留给外层自定义处理)
	//virtual bool ReadXml(string filename, string fullpath);
	//处理 .lan 文件
	virtual bool ReadLan(string filename, string fullpath);
protected:
	//保存文件和对应的路径
	map<string, boost::filesystem::path> mFilePaths;
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
	//注册的配置文件类型
	map<string, ThisFunc> mTypes;
};