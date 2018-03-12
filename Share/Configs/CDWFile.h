#pragma once

class CDWFile : public IDWFile {
public:
	~CDWFile();
public:
	//����
	void Build(string& word) override;
	//ƥ��
	INT Match(string& source, string& matched) override;
	//���
	void Clear() override;
protected:
	void BuildChild(string& word, int pos, DWNode* node);
	void ClearChild(DWNode* node);
	INT MatchChild(string& source, int pos, DWNode* node);
};