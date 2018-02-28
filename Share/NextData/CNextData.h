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
	//用于存储临时数据
	UINT mivalue{ 0 };   
	vector<UINT> mUInts;
	vector<bool> mBools;
};