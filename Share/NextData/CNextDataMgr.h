#pragma once

//next data 事件的类型列表
enum ENextDataKeyType {
	ENDKT_LoginSession = 0,
	ENDKT_LoginAccount = 1
};
/************************************************************************
	Next Data 主要用于解决时序问题 或某些需要等待前置条件完成的逻辑
************************************************************************/
class CNextDataMgr : public CSingleton<CNextDataMgr>
{
SINGLETION_FRIEND_CLASS_REGISTER(CNextDataMgr);
private:
	CNextDataMgr() = default;
	~CNextDataMgr();
public:
	//注册next data 事件 返回用于保存数据的对象
	CNextData* createTemp(CSPNextData& data);
	//处理注册的next data的事件
	template<typename T>
	void handleTemp(CSPNextData& data, T *handle, TypeFunc<T> func) {
		string key = data.SerializeAsString();
		auto it = mTemps.find(key);
		if (it == mTemps.end()) {
			return;
		}
		if (it->second) {
			it->second->handle<T>(handle, func);
			delete it->second;
		}
		mTemps.erase(it);
	}
	//获取注册的next data事件
	CNextData* findTemp(CSPNextData& data);
	//异常情况的清理
	void dirtyHandleTemp(CSPNextData& data);  //这里其实是删除操作
private:
	//保存所有注册的next data事件
	map<string, CNextData*> mTemps;
};