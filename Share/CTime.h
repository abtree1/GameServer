#pragma once

#include <time.h>

//这个类做成纯静态类 方便使用
class CTime {
public:
	//获取当前时间戳
	static time_t GetTimeStamp();
	//时间转时间戳
	static time_t GetTimeStamp(std::tm t);
	//计算后的时间(为正数表示时间向前 为负数表示时间向后)
	static time_t GetTimeStamp(time_t t, UINT second);
	static time_t GetTimeStamp(time_t t, UINT day, UINT hour, UINT minute, UINT second);
	static time_t GetTimeStamp(time_t t, UINT year, UINT month, UINT day, UINT hour, UINT minute, UINT second);
	static time_t GetTimeStamp(std::tm& t, UINT second);
	static time_t GetTimeStamp(std::tm& t, UINT day, UINT hour, UINT minute, UINT second);
	static time_t GetTimeStamp(std::tm& t, UINT year, UINT month, UINT day, UINT hour, UINT minute, UINT second);
	//获取当前时间
	static std::tm GetTime();
	//时间戳转时间
	static std::tm GetTime(time_t t);
};