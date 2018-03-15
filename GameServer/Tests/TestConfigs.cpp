#include "stdafx.h"
#include "TestConfigs.h"
#include "rapidxml.hpp"

using namespace rapidxml;

bool TestConfigs::TestConf() {
	ConfigFile* file = IConfigMgr::GetInstance()->GetConfFile("test");
	if (file) {
		ConfDataBlock* block = file->GetCfg(3);
		if (block) {
			int id = block->GetIntValue("id");
			string name = block->GetStringValue("name");
			float money = block->GetFloatValue("money");
			double power = block->GetDoubleValue("power");
			char dtype = block->GetCharValue("type");
			bool sex = block->GetBoolValue("sex");

			cout << "id:" << id << " "
				<< "name:" << name.c_str() << " "
				<< "money:" << money << " "
				<< "power:" << power << " "
				<< "type:" << dtype << " "
				<< "sex:" << std::boolalpha << sex << endl;
		}
	}
	return true;
}

bool TestConfigs::TestProp() {
	INT zoneid = IConfigMgr::GetInstance()->GetSettingValue<INT>("serverzeroid");
	INT serverid = IConfigMgr::GetInstance()->GetSettingValue<INT>("serverid");

	string dbip = IConfigMgr::GetInstance()->GetSettingValue<string>("dbip");
	string dbuser = IConfigMgr::GetInstance()->GetSettingValue<string>("dbuser");
	string dbpasswd = IConfigMgr::GetInstance()->GetSettingValue<string>("dbpasswd");
	string dbname = IConfigMgr::GetInstance()->GetSettingValue<string>("dbname");
	INT dbport = IConfigMgr::GetInstance()->GetSettingValue<INT>("dbport");
	string dbalter = IConfigMgr::GetInstance()->GetSettingValue<string>("dblogtable");
	cout << zoneid << " " << serverid << endl;
	cout << dbip.c_str() << " " << dbuser << " "
		<< dbpasswd.c_str() << " " << dbname.c_str() << " "
		<< dbport << " " << dbalter.c_str() << endl;
	return true;
}

bool TestConfigs::TestDirtyWord() {
	string str = "asd2wrsdvcwdqadbdc";
	string out = "";
	INT pos = IConfigMgr::GetInstance()->MatchDWDef(str, out);
	if (pos > 0) {
		cout << "Matched word \"" << out.c_str()
			<< "\" in string \"" << str.c_str()
			<< " \" in the position of " << pos << endl;
	}
	else {
		cout << "Unmatched any dirty words in string \""
			<< str.c_str() << "\"" << endl;
	}
	return true;
}

bool TestConfigs::TestLanguage() {
	ILanguage* pLan = IConfigMgr::GetInstance()->GetLanConf();
	string str1 = pLan->GetDefData(1);
	string str2 = pLan->GetDefData(3);
	string str3 = pLan->GetDefData(6, "default");
	cout << str1.c_str() << endl;
	cout << str2.c_str() << endl;
	cout << str3.c_str() << endl;
	return true;
}

bool TestConfigs::TestReadAuto() {
	IConfigMgr::GetInstance()->ReadFile<TestConfigs>("Regions/r1001", this, CLASS_FUNC(TestConfigs, ReadXML), true);
	return true;
}

bool TestConfigs::ReadXML(ifstream& file) {
	//读出整个文件
	auto size = file.tellg();
	std::string text(size, '\0'); // construct string to stream size
	file.seekg(0);
	file.read(&text[0], size);
	file.close();
	if (text.empty()) {
		return false;
	}
	//解析xml
	xml_document<> doc;
	doc.parse<0>(const_cast<char*>(text.c_str()));

	auto root = doc.first_node("root");
	cout << root->name() << endl;
	auto pos = root->first_node("BornBos");
	auto attr = pos->first_attribute("PosX");
	cout << atof(attr->value()) << endl;
	attr = attr->next_attribute("PosY");
	cout << atof(attr->value()) << endl;
	attr = attr->next_attribute("PosZ");
	cout << atof(attr->value()) << endl;
	auto RoomList = pos->next_sibling("RoomList");
	cout << RoomList->name() << endl;
	return true;
}