#pragma once

//����ֻ�������ݿ�������ص���Ϣ 
//�������ݿ���в���
class CDBConfig {
public:
	bool Read(string filepath);
public:
	string GetConnStr() { return mConnStr; }
	string GetDBCreate() { return mDBCreate; }
	string GetHasAlter() { return mDBAlter; }
	string GetAlterCreate() { return mDBAlterCreate; }
	string GetQueryAlter() { return mQueryAlter; }
	map<INT, string>& GetMerge() { return mDBMerge; }
private:
	//�������ݿ���ַ���
	string mConnStr{ "tcp://%s:%d?useServerPrepStmts=true&cachePrepStmts=true" };
	//�������ݿ���ַ���
	string mDBCreate{ "CREATE DATABASE IF NOT EXISTS %s DEFAULT CHARSET utf8 COLLATE utf8_general_ci; " };
	//��ѯ���ݿ���¼�¼���Ƿ���ڵ��ַ���
	string mDBAlter{ "SELECT COUNT(*) as ex FROM information_schema.`TABLES` WHERE TABLE_NAME = '%s' and TABLE_SCHEMA = '%s';" };
	//�������ݿ���¼�¼��
	string mDBAlterCreate{ "CREATE TABLE `%s` (`id` int(11) NOT NULL, PRIMARY KEY (`id`) ) ENGINE=InnoDB DEFAULT CHARSET=utf8;" };
	//���ݿ���¼�¼��ѯ
	string mQueryAlter{ "SELECT * FROM `%s`;" };
	//���ݿ��������
	map<INT, string> mDBMerge;
};