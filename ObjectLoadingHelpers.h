//Bradley Macdonald
//2020
#ifndef OBJECT_LOADING_HELPERS_H_INCLUDED
#define OBJECT_LOADING_HELPERS_H_INCLUDED
#include "OSDefines.h"

#ifdef LIN_BUILD
#include <dlfcn.h>
#endif //LIN_BUILD

#ifdef WIN_BUILD
#include <Windows.h>
#ifdef UNICODE
static std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
#endif //UNICODE
#endif //WIN_BUILD
//Theses are here because we don't want to include Windows.h everywhere TypeDefs.h is used.
#ifdef WIN_BUILD
typedef HINSTANCE LibInstance;
#elif defined(LIN_BUILD)
typedef void* LibInstance;
#endif //WIN_BUILD

//Functions for loading libs and getting functions from the libs
inline LibInstance LoadLibObject(const char* path) {
	LibInstance instance = nullptr; //NOTE Should this be NULL instead.

	#if defined(WIN_BUILD)
	#if defined(UNICODE)
		//We only have to do this if we are using UNICODE
		std::wstring wstr = s2ws(path);
		LPCWSTR wpath = wstr.c_str();
		instance = LoadLibrary(wpath);
	#else
		instance = LoadLibrary(path);
	#endif //UNICODE
	#elif defined(LIN_BUILD)
		instance = dlopen(path, RTLD_LAZY);
	#endif //WIN_BUILD
		return instance;
}

template<typename T>
inline T GetLibObjectFunction(LibInstance i, const char * funcName)
{
#ifdef WIN_BUILD
	T func = (T)GetProcAddress(i, funcName);
#elif defined(LIN_BUILD)
	T func = (T)dlsym(i, funcName);
#endif
	return func;
}

inline bool CloseLibObject(LibInstance i) {
	#if defined(WIN_BUILD)
		return FreeLibrary(i);
	#elif defined(LIN_BUILD)
		int err = dlclose(i);
		if (!err) {
			return true;
		}
	#endif // WIN_BUILD
		return false;
}

#endif //OBJECT_LOADING_HELPERS_H_INCLUDED
