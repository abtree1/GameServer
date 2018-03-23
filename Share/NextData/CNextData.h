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
	//����ֻ��ŵ������ݵĴ���
	template<typename T>
	void SetData(T data) {
		mData.SetValue<T>(data);
	}
	//����ֻ��ŵ������ݵĶ�ȡ
	template<typename T>
	T GetData() {
		return mData.GetValue<T>();
	}
	//����ϵ�����ݵĴ���
	template<typename T>
	void AddData(T data) {
		VarValue vv;
		vv.SetValue<T>(data);
		mTmpDatas.push_back(vv);
	}
	//����ϵ�����ݵĶ�ȡ
	template<typename T>
	T GetData(int index) {
		return mTmpDatas[index].GetValue<T>();
	}
public:
	//���ڴ洢��ʱ����
	VarValue mData;
	vector<VarValue> mTmpDatas;
};