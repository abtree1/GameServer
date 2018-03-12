#include "stdafx.h"

bool CLanguage::Read(string filepath) {
	//���ļ�
	ifstream ss(filepath, ios::in | ios::ate);
	if (!ss.is_open()) {
		cerr << "Open File Failed " << filepath.c_str() << endl;
		return false;
	}
	// read entire file into string
	auto size = ss.tellg();
	std::string file(size, '\0'); // construct string to stream size
	ss.seekg(0);
	ss.read(&file[0], size);
	if(file.empty()){
		cerr << "Read File Failed " << filepath.c_str() << endl;
		return false;
	}
	//��ȡ�����������
	boost::filesystem::path path(filepath, boost::filesystem::native);
	string lan = path.stem().string();
	map<INT, string> &data = mDatas[lan];
	if (!data.empty()) {
		data.clear();
	}
	//���������
	vector<string> pai;
	SplitString(file, pai, "###");
	int id = 0;
	size = pai.size();
	for (int i = 0; i < size; ++i) {
		id = atoi(pai[i].c_str());
		if (id <= 0) {
			cerr << "read comfig \"" << filepath.c_str()
				<< " \" with id \"" << pai[i] << " \" error"
				<< endl;
			++i;  //������Ҫ�������� value ��
			continue;
		}
		++i;
		if (i < size) {
			//�������
			data.insert({ id, pai[i] });
		}
	}
	return true;
}