#pragma once

class TestConfigs {
public:
	bool TestConf() {
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

	bool TestProp() {
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

	bool TestDirtyWord() {
		string str = "asd2wrsdvcwdqadbdc";
		string out = "";
		INT pos = IConfigMgr::GetInstance()->MatchDWDef(str, out);
		if (pos > 0) {
			cout << "Matched word \"" << out.c_str()
				<< "\" in string \"" << str.c_str()
				<< " \" in the position of " << pos << endl;
		}else{
			cout << "Unmatched any dirty words in string \""
				<< str.c_str() << "\"" << endl;
		}
		return true;
	}

	bool TestLanguage() {
		ILanguage* pLan = IConfigMgr::GetInstance()->GetLanConf();
		string str1 = pLan->GetDefData(1);
		string str2 = pLan->GetDefData(3);
		string str3 = pLan->GetDefData(6, "default");
		cout << str1.c_str() << endl;
		cout << str2.c_str() << endl;
		cout << str3.c_str() << endl;
		return true;
	}
};