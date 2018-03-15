#pragma once

//���ö�ٲ��ٹ������ж��� 
//��Ӧ��ÿ�������Լ�����
//enum class EIdType;

//Id������ �����������id����
class CIdentity {
public:
	//��ȡһ���µ�id
	static u32 NewId(EIdType type);
	//���ĳһ��Ľ���
	static void Clear(EIdType type);
	//������н���
	static void ClearAll();
public:
	//���ļ���ȡ
	static void Load();
	//�����ļ�
	static void Save();
private:
	static map<EIdType, u32> mIds;
};