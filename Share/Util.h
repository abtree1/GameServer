#pragma once

typedef int INT;
typedef short SHORT;
typedef long long INT64;

typedef unsigned int UINT;
typedef unsigned short USHORT;
typedef unsigned long long UINT64;

typedef unsigned char u8;
typedef UINT u32;
typedef UINT64 u64;

typedef INT s32;
typedef INT64 s64;

#define  CLASS_FUNC(cla, func) &cla::func

//²ð·Ö×Ö·û´®£¨ÒÔ×Ö·û·Ö¸î£©
extern void SplitString(string source, vector<string>& vec, char sp = '|');
//²ð·Ö×Ö·û´®£¨ÒÔ×Ö·û´®·Ö¸î£©
extern void SplitString(string source, vector<string>& vec, string sp);
