// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO:  在此处引用程序需要的其他头文件
#include <iostream>
#include <string>
//thread
#include <thread>
#include <mutex>
//Collection
#include <vector>
#include <map>
using namespace std;
//Singleton
#include "../Share/Singleton.h"
//Time
#include "../Share/CTime.h"
//google proto buff
#include "ProtoBuff/pb.h"
using namespace NetProto;
#include "ProtoBuff/IProto.h"
#include "ProtoBuff/ProtoMgr.h"
//NetIOCP
#include "../NetIOCP/ISession.h"
#include "Network/CSession.h"
#include "Network/CSessionHandle.h"
#include "Network/CSessionMgr.h"
//Player
#include "Player/Components/IPlayerData.h"
#include "Player/Components/CBaseData.h"
#include "Player/CPlayer.h"
#include "Player/CPlayerMgr.h"
#include "Player/PlayerMsg.h"
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
//Mysql
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "cppconn/statement.h"
#include "cppconn/resultset.h"
#include "cppconn/prepared_statement.h"
//DB
#include "DB/IDBTask.h"
#include "DB/IThread.h"
#include "DB/CThreadSave.h"
#include "DB/CThreadLoad.h"