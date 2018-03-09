#include "stdafx.h"

//ConfDataBlock::~ConfDataBlock() {
//	//清理工作
//	for (auto &it : mData) {
//		if (it.second) {
//			delete it.second;
//		}
//	}
//}

void ConfDataBlock::SetBoolValue(string& name, bool value) {
	SetValue<bool>(name, value);
}

void ConfDataBlock::SetCharValue(string& name, char value) {
	SetValue<char>(name, value);
}

void ConfDataBlock::SetDoubleValue(string& name, double& value) {
	SetValue<double>(name, value);
}

void ConfDataBlock::SetFloatValue(string& name, float& value) {
	SetValue<float>(name, value);
}

void ConfDataBlock::SetIntValue(string& name, INT value) {
	SetValue<INT>(name, value);
}

void ConfDataBlock::SetStringValue(string& name, string& value) {
	SetValue<string>(name, value);
}

bool ConfDataBlock::GetBoolValue(string& name, bool& value) {
	return GetValue<bool>(name, value);
}

bool ConfDataBlock::GetCharValue(string& name, char& value) {
	return GetValue<char>(name, value);
}

bool ConfDataBlock::GetDoubleValue(string& name, double& value) {
	return GetValue<double>(name, value);
}

bool ConfDataBlock::GetFloatValue(string& name, float& value) {
	return GetValue<float>(name, value);
}

bool ConfDataBlock::GetIntValue(string& name, INT& value) {
	return GetValue<INT>(name, value);
}

bool ConfDataBlock::GetStringValue(string& name, string& value) {
	return GetValue<string>(name, value);
}

INT ConfDataBlock::GetIntValue(string name) {
	INT value;
	if (GetValue<INT>(name, value))
		return value;
	return 0;
}

float ConfDataBlock::GetFloatValue(string name) {
	float value;
	if (GetValue<float>(name, value))
		return value;
	return 0.0f;
}

double ConfDataBlock::GetDoubleValue(string name) {
	double value;
	if (GetValue<double>(name, value))
		return value;
	return 0.0;
}

char ConfDataBlock::GetCharValue(string name) {
	char value;
	if (GetValue<char>(name, value))
		return value;
	return '\0';
}

string ConfDataBlock::GetStringValue(string name) {
	string value;
	if (GetValue<string>(name, value))
		return value;
	return "";
}

bool ConfDataBlock::GetBoolValue(string name) {
	bool value;
	if (GetValue<bool>(name, value))
		return value;
	return false;
}