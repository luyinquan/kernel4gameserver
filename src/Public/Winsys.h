#ifndef __Windows_h__
#define __Windows_h__

#ifdef WIN32
#ifndef _WINSOCK2API_  
#include <WinSock2.h>  
#endif  
#ifndef _WINDOWS_  
#include <Windows.h>
#endif  
#include <stdio.h>
#include <Wincrypt.h>
#include <shlwapi.h>
#include <Mswsock.h>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <process.h>
#include <tchar.h>
#include <stdint.h>
#include <direct.h>

#ifdef _DEBUG
#define DEBUG_CLIENTBLOCK new( _CLIENT_BLOCK, __FILE__, __LINE__)
#else
#define DEBUG_CLIENTBLOCK
#endif

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#pragma comment( lib, "ws2_32.lib" )
#pragma comment(lib, "shlwapi.lib")

typedef unsigned char u8;
typedef unsigned short u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef char s8;
typedef short s16;
typedef int32_t s32;
typedef int64_t s64;

#define THREAD_FUN unsigned int
#define ThreadID DWORD

#define CSLEEP(n) Sleep(n)
#define SafeSprintf sprintf_s

#define ECHO(format, ...) { \
	char log[1024] = {0}; \
	SafeSprintf(log, sizeof(log), "%s:%d:%s"#format, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
	printf("%s\n", log);}

#define ECHO_TRACE(format, ...) {\
    char _log[1024] = {0}; \
    SafeSprintf(_log, sizeof(_log), format, ##__VA_ARGS__); \
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN); \
    printf("[trace]%s|%d|%s>>>%s\n", __FILE__, __LINE__, __FUNCTION__, _log); \
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_INTENSITY); \
}

#define ECHO_ERROR(format, ...) {\
    char _log[1024] = {0}; \
    SafeSprintf(_log, sizeof(_log), format, ##__VA_ARGS__); \
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); \
    printf("[error]%s|%d|%s>>>%s\n", __FILE__, __LINE__, __FUNCTION__, _log); \
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_INTENSITY); \
}

#endif //WIN32

#endif //__Windows_h__

