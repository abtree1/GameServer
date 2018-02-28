#include "stdafx.h"
#include "CTime.h"

time_t CTime::GetTimeStamp() {
	return time(nullptr);
}

time_t CTime::GetTimeStamp(std::tm t) {
	return mktime(&t);
}

time_t CTime::GetTimeStamp(time_t t, UINT second) {
	return t + second;
}

time_t CTime::GetTimeStamp(time_t t, UINT day, UINT hour, UINT minute, UINT second) {
	return GetTimeStamp(GetTime(t), day, hour, minute, second);
}

time_t CTime::GetTimeStamp(time_t t, UINT year, UINT month, UINT day, UINT hour, UINT minute, UINT second) {
	return GetTimeStamp(GetTime(t), year, month, day, hour, minute, second);
}

time_t CTime::GetTimeStamp(std::tm& t, UINT second) {
	t.tm_sec += second;
	return GetTimeStamp(t);
}

time_t CTime::GetTimeStamp(std::tm& t, UINT day, UINT hour, UINT minute, UINT second) {
	t.tm_mday += day;
	t.tm_hour += hour;
	t.tm_min += minute;
	return GetTimeStamp(t, second);
}

time_t CTime::GetTimeStamp(std::tm& t, UINT year, UINT month, UINT day, UINT hour, UINT minute, UINT second) {
	t.tm_year += year;
	t.tm_mon += month;
	t.tm_mday += day;
	t.tm_hour += hour;
	t.tm_min += minute;
	t.tm_sec += second;
	return GetTimeStamp(t);
}

std::tm CTime::GetTime() {
	return GetTime(GetTimeStamp());
}

std::tm CTime::GetTime(time_t t) {
	return *localtime(&t);
}