#pragma once

//�������ڲ���
class TestConfigs {
public:
	//����Conf����������
	bool TestConf();
	//����prop����������
	bool TestProp();
	//����������
	bool TestDirtyWord();
	//���Զ�����
	bool TestLanguage();
	//�����Զ������ݶ�ȡ
	bool TestReadAuto();
	//��ȡXML����
	bool ReadXML(ifstream& file);
};