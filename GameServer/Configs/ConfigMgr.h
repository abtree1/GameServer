#pragma once

class CConfigMgr : public CSingleton<CConfigMgr>, public IConfigMgr {
	SINGLETION_FRIEND_CLASS_REGISTER(CConfigMgr)
protected:
	CConfigMgr();
	virtual ~CConfigMgr();
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
		return GetPropValue<T>(DEFSETTING, title);
	}
public: //���� ������(.dw) �����ļ�
	//��ȡ�����������ļ�
	IDWFile* GetDWFile(string name);
	//��ȡĬ�������������ļ�
	IDWFile* GetDefDWFile() { return GetDWFile(DEFDIRTYWORD); }
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
public:
	//���� .conf �ļ�
	virtual bool ReadConf(string filename, string fullpath) override;
	//���� .prop �ļ�
	virtual bool ReadProp(string filename, string fullpath) override;
	//���� .dw �ļ�
	virtual bool ReadDW(string filename, string fullpath) override;
	//���� .sqls �ļ�
	virtual bool ReadSqls(string filename, string fullpath) override;
	//���� .xml �ļ� (��������Զ��崦��)
	//virtual bool ReadXml(string filename, string fullpath);
	//���� .lan �ļ�
	virtual bool ReadLan(string filename, string fullpath) override;
protected:
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
};

extern CConfigMgr* gConfigMgr;