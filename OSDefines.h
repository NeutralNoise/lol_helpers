//Bradley Macdonald
//2020
#ifndef OS_DEFINES_H_INCLUDED
#define OS_DEFINES_H_INCLUDED

#define USE_ERROR_MANAGER //Use the built in error manager
//Build Information
#if defined(_WIN32) || defined(_WIN64)
#define WIN_BUILD
#if defined(_WIN64)
#define WIN64_BUILD
#else
#define WIN32_BUILD
#endif
#elif __linux__
#define LIN_BUILD
#if defined(__LP64__ ) || defined(_LP64)
#define LIN64_BUILD
#else
#define LIN32_BUILD
#endif
//Treat cygwin builds likes its on linux
//have some cygwin ones just incase its needed for things like dll/so
#elif __CYGWIN__
#define LIN_BUILD
#define CYG_BUILD
#if defined(__LP64__ ) || defined(_LP64)
#define LIN64_BUILD
#define CYG64_BUILD
#else
#define LIN32_BUILD
#define CYG32_BUILD
#endif
#endif

#endif //OS_DEFINES_H_INCLUDED
