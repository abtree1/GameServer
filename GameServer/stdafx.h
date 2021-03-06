// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include "configdef.h"

#include <stdio.h>
#include <tchar.h>

// TODO:  在此处引用程序需要的其他头文件
#include <iostream>
#include <string>
#include <sstream>
//thread
#include <thread>
#include <mutex>
//Collection
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
//boost
#include "boost/filesystem.hpp"
#include "boost/variant.hpp"
//Util
#include "../Share/Util.h"
#include "../Share/identity.h"
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
//Mysql
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "cppconn/statement.h"
#include "cppconn/resultset.h"
#include "cppconn/prepared_statement.h"
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
//Player
#include "Player/Components/IPlayerData.h"
#include "Player/Components/CVIPData.h"
#include "Player/CPlayer.h"
#include "Player/CPlayerMgr.h"
#include "msg/PlayerMsg.h"
#include "msg/FightServerMsg.h"
//Next Data
#include "../Share/NextData/CNextData.h"
#include "../Share/NextData/CNextDataMgr.h"
//RankList
#include "../Share/RankList/RankListLogic.h"
#include "../Share/RankList/IRankListData.h"
#include "../Share/RankList/IRankListSync.h"
#include "../Share/RankList/IRankListASync.h"
//Timer Task
#include "../Share/TimerTask/CTimerTaskHandle.h"
#include "../Share/TimerTask/CTimerTaskEvent.h"
#include "../Share/TimerTask/CTimerTaskMgr.h"
#include "Logic/TimerTask/TimerTask.h"
//DB
#include "DB/IDBTask.h"
#include "DB/IThread.h"
#include "DB/CThreadSave.h"
#include "DB/CThreadLoad.h"
//DB Task
#include "DB/Task/MysqlTask.h"