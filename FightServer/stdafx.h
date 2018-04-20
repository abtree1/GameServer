// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <string>
#include <sstream>
//thread
#include <thread>
#include <mutex>
//Collection
#include <vector>

using namespace std;
//boost
#include "boost/filesystem.hpp"
#include "boost/variant.hpp"
//Util
#include "../Share/Util.h"
//Singleton
#include "../Share/Singleton.h"
//Time
#include "../Share/CTime.h"
//google proto buff
#include "../Share/ProtoBuff/pb.h"
using namespace NetProto;
#include "../Share/ProtoBuff/IMsgHandle.h"
#include "../Share/ProtoBuff/IProto.h"
#include "../Share/ProtoBuff/ProtoMgr.h"
//NetIOCP
#include "../NetIOCP/ISession.h"
#include "../Share/Network/CSession.h"
#include "../Share/Network/CSessionHandle.h"
#include "../Share/Network/CSessionMgr.h"
//MSG
#include "msg/GameServerMsgHandle.h"
//Configs
#include "../Share/Configs/IConfData.h"
#include "../Share/Configs/ConfBlock.h"
#include "../Share/Configs/ConfigFile.h"
#include "../Share/Configs/IDWNode.h"
#include "../Share/Configs/CDWFile.h"
#include "../Share/Configs/ILanguageFile.h"
#include "../Share/Configs/CLanguageFile.h"
#include "../Share/Configs/CDBConfig.h"
#include "../Share/Configs/IConfigMgr.h"
#include "Configs/ConfigMgr.h"
