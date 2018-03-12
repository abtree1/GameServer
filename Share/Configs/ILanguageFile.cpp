#include "stdafx.h"

map<INT, string>* ILanguage::GetLanguageData(string& lan) {
	auto it = mDatas.find(lan);
	if (it == mDatas.end())
		return nullptr;
	return &(it->second);
}

string ILanguage::GetData(INT id, string& lan) {
	auto* conf = GetLanguageData(lan);
	if (!conf)
		return "";
	auto it = conf->find(id);
	if (it == conf->end()) {
		return "";
	}
	return it->second;
}

string ILanguage::GetDefData(INT id, string def) {
	string find = GetDefData(id);
	return (find == "" ? def : find);
}