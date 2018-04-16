// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
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

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 
#include <windows.h>

#include "../Dependences/UnlockQueue/concurrentqueue.h"

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
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