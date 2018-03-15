#pragma once

//这个枚举不再公共类中定义 
//而应该每个工程自己定义
//enum class EIdType;

//Id管理类 管理服务器的id分配
class CIdentity {
public:
	//获取一个新的id
	static u32 NewId(EIdType type);
	//清除某一项的进度
	static void Clear(EIdType type);
	//清除所有进度
	static void ClearAll();
public:
	//从文件读取
	static void Load();
	//存入文件
	static void Save();
private:
	static map<EIdType, u32> mIds;
};