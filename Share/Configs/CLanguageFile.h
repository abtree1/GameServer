#pragma once

class CLanguage : public ILanguage {
public:
	//ֱ��ʹ�ø���Ĺ��캯��
	using ILanguage::ILanguage;
public:
	bool Read(string filepath) override;
};