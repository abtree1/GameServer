// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <string>
#include <thread>
#include <list>
#include <vector>
#include <map>
#include <memory>
using namespace std;

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
// Windows 头文件: 
#include <windows.h>

#include "../Dependences/UnlockQueue/concurrentqueue.h"

// TODO:  在此处引用程序需要的其他头文件
#include "../Share/Singleton.h"
#include "share/IOOperation.h"
#include "share/Statistics.h"
#include "share/WSAHelper.h"

#define BUFFER_SIZE 1024
#define INT_SIZE 4

#include "ISession.h"
#include "IOCompletionPort.h"
#include "IOBuffer.h"
#include "IConnectionManager.h"
#include "IServerEvent.h"
#include "ISocketEvent.h"
#include "ISocketFactory.h"
#include "ISocketEventDispatcher.h"
#include "ITaskFactory.h"
#include "DefaultTaskFactory.h"
#include "Socket.h"
#include "TcpSocketEventHandler.h"
#include "TcpSocketEventDispatcher.h"
#include "TcpSocketFactory.h"
#include "TcpConnectionManager.h"
#include "CSessionMgr.h"