#pragma once


#ifdef WIN32

#include <Windows.h>

#endif

#ifdef BUILD_DLL
	#define FORGE_API __declspec(dllexport)
#else
	#define FORGE_API __declspec(dllimport)
#endif

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

#include "Common\Logger.h"
#include "Core/PerGameSettings.h"
#include "Common\Time.h"