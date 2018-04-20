#include "stdafx.h"

typedef boost::filesystem::path Path;

bool IConfigMgr::IsRegisterType(string& type) {
	return (mTypes.find(type) != mTypes.end());
}

bool IConfigMgr::RegisterType(string type, ThisFunc func) {
	if (IsRegisterType(type))
		return false;
	mTypes[type] = func;
	return true;
}

bool IConfigMgr::Read(string basePath) {
	//检查路径是否合法
	Path fullpath(basePath, boost::filesystem::native);
	if (!boost::filesystem::exists(fullpath)) {
		printf("%s, is not a real path", basePath.c_str());
		return false;
	}
	//读取所有的配置文件和路径
	if (!ReadFilePath(fullpath, "")) {
		printf("read all config file pathes error");
		return false;
	}
	//读取每种注册类型的配置文件的内容
	for (auto &itpath : mFilePaths) {
		auto ittype = mTypes.find(itpath.second.extension().string());
		if(ittype == mTypes.end())
			continue;   //非注册类型的文件
		if(!ittype->second)  //注册了类型 但没注册处理函数
			continue;
		//读取该文件
		bool ret = (this->*(ittype->second))(itpath.first, itpath.second.string());
		if (!ret)
			return false;
	}
	return true;
}

boost::filesystem::path* IConfigMgr::GetFilePath(string filename) {
	auto it = mFilePaths.find(filename);
	if (it == mFilePaths.end())
		return nullptr;
	return &(it->second);
}

//获取路径下（包括子路径）所有文件
bool IConfigMgr::ReadFilePath(boost::filesystem::path& fullpath, string filehead) {
	try {
		//遍历路径
		boost::filesystem::recursive_directory_iterator end_iter;
		for (boost::filesystem::recursive_directory_iterator iter(fullpath); iter != end_iter; iter++) {
			Path pat = iter->path();
			//检查文件名是否以('.')开始 是则为无效文件 
			if (pat.stem().empty() || pat.stem().string()[0] == '.')
				continue;
			//如果是文件夹
			if (boost::filesystem::is_directory(*iter)) {
				//读取文件夹内文件
				if (!ReadFilePath(pat, filehead + pat.stem().string() + "/"))
					return false;  //如果读取异常 返回false
			}
			else {
				//如果不是注册的配置文件类型 不做处理
				string ext = pat.extension().string();
				if (mTypes.find(ext) == mTypes.end())
					continue;
				//保存文件路径
				string filename = filehead + pat.stem().string();
				mFilePaths[filename] = pat;
			}
		}
	}
	catch (const std::exception & ex) {
		std::cerr << ex.what() << std::endl;
		return false;
	}
	return true;
}

bool IConfigMgr::DoReadProp(ConfDataBlock& block, string fullpath) {
	//打开文件
	ifstream ss;
	ss.open(fullpath, ifstream::in);
	if (!ss.is_open()) {
		cerr << "Open File Failed " << fullpath.c_str() << endl;
		return false;
	}
	string s;
	vector<string> head;
	//读取到 # 号处
	while (ss >> s) {
		if (s != "#")
			continue;

		//读取标题
		ss >> s >> s;
		head.clear();
		SplitString(s, head, ':');
		if (head.size() != 2)
		{
			cerr << "read title fail " << s.c_str() << endl;
			return 0;
		}
		//读取数据
		if (head[1] == "int") {
			int i;
			ss >> i;
			block.SetIntValue(head[0], i);
		}
		else if (head[1] == "string") {
			ss >> s;
			block.SetStringValue(head[0], s);
		}
		else if (head[1] == "float") {
			float f;
			ss >> f;
			block.SetFloatValue(head[0], f);
		}
		else if (head[1] == "double") {
			double d;
			ss >> d;
			block.SetDoubleValue(head[0], d);
		}
		else if (head[1] == "char") {
			char c;
			ss >> c;
			block.SetCharValue(head[0], c);
		}
		else if (head[1] == "bool") {
			bool b;
			ss >> std::boolalpha >> b;
			block.SetBoolValue(head[0], b);
		}
		else {
			//表示解析type 异常
			cerr << "read title type fail " << head[1].c_str() << endl;
			ss.close();
			return false;
		}
	}
	ss.close();
	return true;
}