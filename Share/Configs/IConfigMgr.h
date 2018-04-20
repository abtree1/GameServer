#pragma once
class IConfigMgr;
using ThisFunc = bool (IConfigMgr::*)(string, string);
template<typename T>
using ReadFunc = bool (T::*)(ifstream&);

class IConfigMgr {
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
		if (isTail)
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
protected:
	//��ȡĿ¼�µ����������ļ�·��(�����ļ����ļ�)
	bool ReadFilePath(boost::filesystem::path& fullpath, string filehead);
	//��ȡprop�ļ�
	bool DoReadProp(ConfDataBlock& block, string fullpath);
public:
	//���� .conf �ļ�
	virtual bool ReadConf(string filename, string fullpath) { return true; }
	//���� .prop �ļ�
	virtual bool ReadProp(string filename, string fullpath) { return true; }
	//���� .dw �ļ�
	virtual bool ReadDW(string filename, string fullpath) { return true; }
	//���� .sqls �ļ�
	virtual bool ReadSqls(string filename, string fullpath) { return true; }
	//���� .xml �ļ� (��������Զ��崦��)
	//virtual bool ReadXml(string filename, string fullpath);
	//���� .lan �ļ�
	virtual bool ReadLan(string filename, string fullpath) { return true; }
protected:
	//�����ļ��Ͷ�Ӧ��·��
	map<string, boost::filesystem::path> mFilePaths;
	//ע��������ļ�����
	map<string, ThisFunc> mTypes;
};