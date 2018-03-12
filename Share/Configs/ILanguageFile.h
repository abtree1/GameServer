#pragma once

class ILanguage {
public:
	ILanguage(string lan) :mLanguage(lan) {}
public:
	//������ʹ�õ�����
	void SetLan(string lan) { mLanguage = lan; }
	//��ȡ���õ�����
	string &GetLan() { return mLanguage; }
public:
	//��ȡ��������
	virtual bool Read(string filepath) = 0;
public:
	//��ȡ���õ����Ե�����
	virtual map<INT, string>* GetDefLanguageData() { return GetLanguageData(mLanguage); }
	//��ȡָ�����Ե�����
	virtual map<INT, string>* GetLanguageData(string& lan);
	//��ȡ Ĭ�����Ե� ��������
	virtual string GetDefData(INT id) { return GetData(id, mLanguage); }
	//�����ȡʧ�� �ͷ���Ĭ��ֵ
	virtual string GetDefData(INT id, string def);
	//��ȡָ�����Ե�����������
	virtual string GetData(INT id, string& lan);
protected:
	//����Ĭ��ʹ�õ�����
	string mLanguage{ "" };
	//��ͬ���Ե���������
	map<string, map<INT, string>> mDatas;
};