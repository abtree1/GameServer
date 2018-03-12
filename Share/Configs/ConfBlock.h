#pragma once

//�����������ݵĿ�
class ConfDataBlock {
public:
	ConfDataBlock() = default;
	~ConfDataBlock() = default;
public:
	bool Empty() { return mData.empty(); }
	void Clear() { mData.clear(); }
public:
	void SetIntValue(string& name, INT value);
	void SetFloatValue(string& name, float& value);
	void SetDoubleValue(string& name, double& value);
	void SetCharValue(string& name, char value);
	void SetStringValue(string& name, string& value);
	void SetBoolValue(string& name, bool value);

	bool GetIntValue(string& name, INT& value);
	bool GetFloatValue(string& name, float& value);
	bool GetDoubleValue(string& name, double& value);
	bool GetCharValue(string& name, char& value);
	bool GetStringValue(string& name, string& value);
	bool GetBoolValue(string& name, bool& value);

	//�����get �������ʧ�� ����Ĭ��ֵ
	INT GetIntValue(string name);
	float GetFloatValue(string name);
	double GetDoubleValue(string name);
	char GetCharValue(string name);
	string GetStringValue(string name);
	bool GetBoolValue(string name);
public:
	//���ҿ����Ƿ��и�������
	VarValue* FindData(string& name) {
		auto it = mData.find(name);
		if (it != mData.end()) {
			return &(it->second);
		}
		return nullptr;
	}
	//����ĳ�������ֵ
	template<typename T>
	void SetValue(string& name, T& value) {
		VarValue* data = FindData(name);
		if (data) {
			data->SetValue<T>(value);
		}
		else {
			VarValue &data = mData[name]; 
			data.SetValue<T>(value);
		}
	}
	//��ȡĳ�������ֵ
	template<typename T>
	bool GetValue(string& name, T& value){
		VarValue* data = FindData(name);
		if (data) {
			value = data->GetValue<T>();
			return true;
		}
		return false;
	}
protected:
	//������е�����
	map<string, VarValue> mData;
	//map<string, void*> mData;
};