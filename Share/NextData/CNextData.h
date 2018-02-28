#pragma once

class CNextData;
template<typename T>
using TypeFunc = void (T::*)(CNextData* data);

//ע��next data�� �������ݵĶ���
class CNextData
{
public:
	CNextData() = default;
	~CNextData() = default;
public:
	//����ɾ���Ĵ����߼�
	template<typename T>
	void handle(T* handle, TypeFunc<T> pFunc) {
		(handle->*pFunc)(this);
	}
	void dirtyHandle();  //�쳣ɾ���Ĵ����߼�

public:
	//���ڴ洢��ʱ����
	UINT mivalue{ 0 };   
	vector<UINT> mUInts;
	vector<bool> mBools;
};