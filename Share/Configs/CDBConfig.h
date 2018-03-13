#pragma once

//该类只保存数据库配置相关的信息 
//不对数据库进行操作
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
	//连接数据库的字符串
	string mConnStr{ "tcp://%s:%d?useServerPrepStmts=true&cachePrepStmts=true" };
	//创建数据库的字符串
	string mDBCreate{ "CREATE DATABASE IF NOT EXISTS %s DEFAULT CHARSET utf8 COLLATE utf8_general_ci; " };
	//查询数据库更新记录表是否存在的字符串
	string mDBAlter{ "SELECT COUNT(*) as ex FROM information_schema.`TABLES` WHERE TABLE_NAME = '%s' and TABLE_SCHEMA = '%s';" };
	//创建数据库更新记录表
	string mDBAlterCreate{ "CREATE TABLE `%s` (`id` int(11) NOT NULL, PRIMARY KEY (`id`) ) ENGINE=InnoDB DEFAULT CHARSET=utf8;" };
	//数据库更新记录查询
	string mQueryAlter{ "SELECT * FROM `%s`;" };
	//数据库更新配置
	map<INT, string> mDBMerge;
};