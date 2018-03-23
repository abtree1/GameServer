#pragma once

class CNextData;
template<typename T>
using TypeFunc = void (T::*)(CNextData* data);

//注册next data后 保存数据的对象
class CNextData
{
public:
	CNextData() = default;
	~CNextData() = default;
public:
	//正常删除的处理逻辑
	template<typename T>
	void handle(T* handle, TypeFunc<T> pFunc) {
		(handle->*pFunc)(this);
	}
	void dirtyHandle();  //异常删除的处理逻辑
public:
	//用于只存放单个数据的存入
	template<typename T>
	void SetData(T data) {
		mData.SetValue<T>(data);
	}
	//用于只存放单个数据的读取
	template<typename T>
	T GetData() {
		return mData.GetValue<T>();
	}
	//用于系列数据的存入
	template<typename T>
	void AddData(T data) {
		VarValue vv;
		vv.SetValue<T>(data);
		mTmpDatas.push_back(vv);
	}
	//用于系列数据的读取
	template<typename T>
	T GetData(int index) {
		return mTmpDatas[index].GetValue<T>();
	}
public:
	//用于存储临时数据
	VarValue mData;
	vector<VarValue> mTmpDatas;
};