#pragma once

class CLanguage : public ILanguage {
public:
	//直接使用父类的构造函数
	using ILanguage::ILanguage;
public:
	bool Read(string filepath) override;
};