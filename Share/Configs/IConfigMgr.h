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
	//ָ�����͵������ļ��Ƿ�ע��
	bool IsRegisterType(string& type);
	//ע�������ļ�����
	bool RegisterType(string type, ThisFunc func);
public:
	//��ȡ�����ļ�
	bool Read(string basePath);
	//��ȡ�ļ�·�� �����ⲿ��ȡ
	boost::filesystem::path* GetFilePath(string filename);
	//�Զ����ȡ�ļ�
	template<typename T>
	bool ReadFile(string filename, T* CA, ReadFunc<T> func, bool isTail = false) {
		//��ȡ�ļ�·��
		auto it = mFilePaths.find(filename);
		if (it == mFilePaths.end()) {
			cerr << "file not find " << filename.c_str() << endl;
			return false;
		}
		//��ȡ����
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
	//��ȡConf�������ļ�
	ConfigFile* GetConfFile(string name);
public:
	//����prop�����ļ�
	ConfDataBlock* GetPropFile(string name);
	template<typename T>
	T GetPropValue(string name, string title) {
		T t{};  //���ﶨ�����������Ĭ��ֵ;
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
public: //���� ������(.dw) �����ļ�
	//��ȡ�����������ļ�
	IDWFile* GetDWFile(string name);
	//��ȡĬ�������������ļ�
	IDWFile* GetDefDWFile() { return GetDWFile("dirtyword"); }
	//ƥ��Ĭ�������������ļ�
	INT MatchDWDef(string& source, string& matched);
public:
	//��ȡ����������
	ILanguage* GetLanConf() { return mpLanguage; }
	//��ȡĬ����������
	string GetLanDef(INT id) { return mpLanguage->GetDefData(id); }
	string GetLanDef(INT id, string def) { return mpLanguage->GetDefData(id, def); }
public:
	//���ݿ�����
	CDBConfig& GetDBConf() { return mDBCfg; }
protected:
	//��ȡĿ¼�µ����������ļ�·��(�����ļ����ļ�)
	bool ReadFilePath(boost::filesystem::path& fullpath, string filehead);
public:
	//���� .conf �ļ�
	virtual bool ReadConf(string filename, string fullpath);
	//���� .prop �ļ�
	virtual bool ReadProp(string filename, string fullpath);
	//���� .dw �ļ�
	virtual bool ReadDW(string filename, string fullpath);
	//���� .sqls �ļ�
	virtual bool ReadSqls(string filename, string fullpath);
	//���� .xml �ļ� (��������Զ��崦��)
	//virtual bool ReadXml(string filename, string fullpath);
	//���� .lan �ļ�
	virtual bool ReadLan(string filename, string fullpath);
protected:
	//�����ļ��Ͷ�Ӧ��·��
	map<string, boost::filesystem::path> mFilePaths;
	//�����ļ��� �� �����õ�����
	map<string, ConfigFile> mConfs;
	//�������������
	map<string, ConfDataBlock> mProps;
	//�������ļ�
	map<string, IDWFile*> mDWFiles;
	//������
	ILanguage* mpLanguage{nullptr};
	//���ݿ������ļ�
	CDBConfig mDBCfg;
	//ע��������ļ�����
	map<string, ThisFunc> mTypes;
};