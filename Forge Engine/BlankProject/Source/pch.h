#pragma once // This is a preprocessor directive that tells the compiler to include this file only once

#include <Windows.h> // Include the Windows.h header file

#include "../resource.h"

// Define the entry point for the application

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)



#include "Forge.h"

#include "Common\Logger.h"