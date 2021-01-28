//Bradley Macdonald
//2020
#ifndef OBJECT_LOADER__H_INCLUDED
#define OBJECT_LOADER__H_INCLUDED
#include <string>
#include "ObjectLoadingHelpers.h"

#ifdef WIN_BUILD
#include <Windows.h>
#endif // WIN_BUILD

#include <iostream>

class ObjectLoader
{
public:
	ObjectLoader() {};
	~ObjectLoader() {};

	bool LoadObject(std::string path) {
		p_ProcID = LoadLibObject(path.c_str());
		if (!p_ProcID) {
			std::cout << "Unable to load shared libary: " + path + "\n";
			return false;
		}
		std::cout << "Loaded libary: " + path + "\n";
		return true;
	}
	template<typename F>
		F GetFunctionSymbol(const std::string &funcName);

	bool FreeObject() {
		return CloseLibObject(p_ProcID);
	}
private:
	LibInstance p_ProcID = NULL;
};

template<typename F>
inline F ObjectLoader::GetFunctionSymbol(const std::string & funcName)
{

	F func = GetLibObjectFunction<F>(p_ProcID, funcName.c_str());
	if (!func) {
		//TODO Error Message
		std::cout << "Failed to get Function symbol: " + funcName + "\n";
	}
	return func;
}

#endif //!OBJECT_LOADER__H_INCLUDED
