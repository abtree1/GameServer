#pragma once

class VarValue {
public:
	//设置数值
	template<typename T>
	void SetValue(T val) {
		mVal = val;
	}
	//获取数值
	template<typename T>
	T GetValue() {
		return boost::get<T>(mVal);
	}
private:
	//用于存储数据
	boost::variant<int, float, double, std::string, char, bool> mVal;
};