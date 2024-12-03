#pragma once
#include <string>



class FORGE_API Logger {

	//Getters and setters for single static class
private:
	static Logger* inst;

public:

	static Logger* Instance() 
	{
		return inst;
	}

public:

	~Logger();

	Logger();

	static VOID PrintLog(const WCHAR* fmt, ...);


	static std::wstring LogDirectory();
	static std::wstring LogFile();

	//Prints a line of '-' chars
	static VOID PrintDebugSeperator();

	//Checks if the MTail process is running
	static BOOL IsMTailRunning();

	//Starts the MTail process
	static VOID StartMTail();
};