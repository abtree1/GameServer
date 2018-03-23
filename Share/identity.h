#pragma once

//这个枚举不再公共类中定义 
//而应该每个工程自己定义
//enum class EIdType;

//这里建立一个基类
class IIdentify {
public:
	//获取一个新的id
	virtual u32 NewId(EIdType type) = 0;
	//清除某一项的进度
	virtual void Clear(EIdType type) = 0;
	//清除所有进度
	virtual void ClearAll() = 0;
public:
	//读取
	virtual void Load() = 0;
	//存入
	virtual void Save() = 0;
	//是否加载完成
	virtual bool IsLoadFinish() { return mpLoadFinish; }
	virtual void LoadFinish() { mpLoadFinish = true; }
protected:
	bool mpLoadFinish{ false };
	//保存所有注册的id
	map<string, u32> mIds;
};

//Id管理类 管理服务器的id分配(文件管理)
class CIdentity : public IIdentify {
public:
	//获取一个新的id
	u32 NewId(EIdType type) override;
	//清除某一项的进度
	void Clear(EIdType type) override;
	//清除所有进度
	void ClearAll() override;
public:
	//从文件读取
	void Load() override;
	//存入文件
	void Save() override;
};

//Id管理类第2️个版本 数据库管理
class CIdentityImpl : public IIdentify {
public:
	//获取一个新的id
	u32 NewId(EIdType type) override;
	//清除某一项的进度
	void Clear(EIdType type) override;
	//清除所有进度
	void ClearAll() override;
public:
	//从文件读取
	void Load() override;
	//存入文件
	void Save() override;
public:
	//获取所有Id
	map<string, u32>& GetAllIds() { return mIds; }
};
//全局访问变量
extern IIdentify* gIdentify;