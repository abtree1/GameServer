#pragma once

//该类用于测试
class TestConfigs {
public:
	//测试Conf型配置数据
	bool TestConf();
	//测试prop型配置数据
	bool TestProp();
	//测试屏蔽字
	bool TestDirtyWord();
	//测试多语言
	bool TestLanguage();
	//测试自定义数据读取
	bool TestReadAuto();
	//读取XML测试
	bool ReadXML(ifstream& file);
};