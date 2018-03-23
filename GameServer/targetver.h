#pragma once

// 包括 SDKDDKVer.h 将定义可用的最高版本的 Windows 平台。

// 如果要为以前的 Windows 平台生成应用程序，请包括 WinSDKVer.h，并将
// 将 _WIN32_WINNT 宏设置为要支持的平台，然后再包括 SDKDDKVer.h。

#include <SDKDDKVer.h>

typedef int INT;
typedef short SHORT;
typedef long long INT64;

typedef unsigned int UINT;
typedef unsigned short USHORT;
typedef unsigned long long UINT64;

typedef unsigned char u8;
typedef UINT u32;
typedef UINT64 u64;

#define  CLASS_FUNC(cla, func) &cla::func
#define  PLAYER_MAX_COUNT 10000000

//默认设置文件
#define DEFSETTING "Setting"
//默认屏蔽字文件
#define DEFDIRTYWORD "dirtyword"
//默认语言
#define DEFLANGUAGE "chinese"
//默认配置文件存放路径
#define CONFIGPATH	"../Configs"
//index 存放文件
#define INDEXFILE	"index.dat"

//定义ID的枚举
enum EIdType {
	EID_TimerTask = 0,
	EID_PlayerId,
};
//定义timer task的枚举
enum ETimerTaskType {
	ETTT_None = 0,  //测试用
};
//next data 事件的类型列表
enum ENextDataKeyType {
	ENDKT_LoginPrepare = 0,  //登录前准备工作
	ENDKT_LoginAccount = 1
};