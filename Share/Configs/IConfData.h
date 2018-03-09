#pragma once

class VarValue {
public:
	//������ֵ
	template<typename T>
	void SetValue(T val) {
		mVal = val;
	}
	//��ȡ��ֵ
	template<typename T>
	T GetValue() {
		return boost::get<T>(mVal);
	}
private:
	//���ڴ洢����
	boost::variant<int, float, double, std::string, char, bool> mVal;
};