#pragma once

#include <time.h>

//��������ɴ���̬�� ����ʹ��
class CTime {
public:
	//��ȡ��ǰʱ���
	static time_t GetTimeStamp();
	//ʱ��תʱ���
	static time_t GetTimeStamp(std::tm t);
	//������ʱ��(Ϊ������ʾʱ����ǰ Ϊ������ʾʱ�����)
	static time_t GetTimeStamp(time_t t, UINT second);
	static time_t GetTimeStamp(time_t t, UINT day, UINT hour, UINT minute, UINT second);
	static time_t GetTimeStamp(time_t t, UINT year, UINT month, UINT day, UINT hour, UINT minute, UINT second);
	static time_t GetTimeStamp(std::tm& t, UINT second);
	static time_t GetTimeStamp(std::tm& t, UINT day, UINT hour, UINT minute, UINT second);
	static time_t GetTimeStamp(std::tm& t, UINT year, UINT month, UINT day, UINT hour, UINT minute, UINT second);
	//��ȡ��ǰʱ��
	static std::tm GetTime();
	//ʱ���תʱ��
	static std::tm GetTime(time_t t);
};