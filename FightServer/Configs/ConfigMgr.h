#pragma once

class CConfigMgr : public CSingleton<CConfigMgr>, public IConfigMgr {
	SINGLETION_FRIEND_CLASS_REGISTER(CConfigMgr)
protected:
	CConfigMgr();
	virtual ~CConfigMgr();
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
public:
	//���� .prop �ļ�
	virtual bool ReadProp(string filename, string fullpath) override;
protected:
	//�������������
	map<string, ConfDataBlock> mProps;
};

extern CConfigMgr* gConfigMgr;