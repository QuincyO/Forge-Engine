#pragma once


#ifdef WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
#define FORGE_API __declspec(dllexport)
#else
#define FORGE_API __declspec(dllimport)
#endif