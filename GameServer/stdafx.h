// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <iostream>
//thread
#include <thread>
//Collection
#include <vector>
#include <map>
using namespace std;
//Singleton
#include "../Share/Singleton.h"
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
#include "Player/PlayerMsg.h"