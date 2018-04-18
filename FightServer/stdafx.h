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
//Util
#include "../Share/Util.h"
//Singleton
#include "../Share/Singleton.h"
//Time
#include "../Share/CTime.h"
//google proto buff
#include "../Share/ProtoBuff/pb.h"
using namespace NetProto;
#include "../Share/ProtoBuff/IProto.h"
#include "../Share/ProtoBuff/ProtoMgr.h"
//NetIOCP
#include "../NetIOCP/ISession.h"
#include "../Share/Network/CSession.h"
#include "../Share/Network/CSessionHandle.h"
#include "../Share/Network/CSessionMgr.h"
//MSG
#include "msg/GameServerMsgHandle.h"
