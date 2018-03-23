#pragma once

// ���� SDKDDKVer.h ��������õ���߰汾�� Windows ƽ̨��

// ���ҪΪ��ǰ�� Windows ƽ̨����Ӧ�ó�������� WinSDKVer.h������
// �� _WIN32_WINNT ������ΪҪ֧�ֵ�ƽ̨��Ȼ���ٰ��� SDKDDKVer.h��

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

//Ĭ�������ļ�
#define DEFSETTING "Setting"
//Ĭ���������ļ�
#define DEFDIRTYWORD "dirtyword"
//Ĭ������
#define DEFLANGUAGE "chinese"
//Ĭ�������ļ����·��
#define CONFIGPATH	"../Configs"
//index ����ļ�
#define INDEXFILE	"index.dat"

//����ID��ö��
enum EIdType {
	EID_TimerTask = 0,
	EID_PlayerId,
};
//����timer task��ö��
enum ETimerTaskType {
	ETTT_None = 0,  //������
};
//next data �¼��������б�
enum ENextDataKeyType {
	ENDKT_LoginPrepare = 0,  //��¼ǰ׼������
	ENDKT_LoginAccount = 1
};