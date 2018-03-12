#pragma once

class CDWFile : public IDWFile {
public:
	~CDWFile();
public:
	//´´½¨
	void Build(string& word) override;
	//Æ¥Åä
	INT Match(string& source, string& matched) override;
	//Çå¿Õ
	void Clear() override;
protected:
	void BuildChild(string& word, int pos, DWNode* node);
	void ClearChild(DWNode* node);
	INT MatchChild(string& source, int pos, DWNode* node);
};