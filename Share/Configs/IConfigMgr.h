#pragma once
class IConfigMgr;
using ClassFunc = bool (IConfigMgr::*)(string, string);

class IConfigMgr : public CSingleton<IConfigMgr> {
	SINGLETION_FRIEND_CLASS_REGISTER(IConfigMgr)
protected:
	IConfigMgr();
	virtual ~IConfigMgr() = default;
public:
	//ָ�����͵������ļ��Ƿ�ע��
	bool IsRegisterType(string& type);
	//ע�������ļ�����
	bool RegisterType(string type, ClassFunc func);
public:
	//��ȡ�����ļ�
	bool Read(string basePath);
public:
	//��ȡConf�������ļ�
	ConfigFile* GetConfFile(string name);
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
	//���� .xml �ļ�
	virtual bool ReadXml(string filename, string fullpath);
	//���� .lan �ļ�
	virtual bool ReadLan(string filename, string fullpath);
protected:
	//�����ļ��Ͷ�Ӧ��·��
	map<string, boost::filesystem::path> mFilePaths;
	//�����ļ��� �� �����õ�����
	map<string, ConfigFile> mConfs;
	//ע��������ļ�����
	map<string, ClassFunc> mTypes;
};