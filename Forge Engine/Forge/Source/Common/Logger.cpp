#include "Forge.h"
#include <fstream>
#include <ShlObj.h>
#include <cstdio>
#include <tlhelp32.h>


Logger* Logger::inst;


Logger::Logger()
{
	inst = this;
}


Logger::~Logger()
{

}

VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	//MessageBox(0, buf, 0, 0);

	//C:\Users\quinc\AppData\Roaming\BlankProject


	std::wfstream outFile;

	outFile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outFile.is_open())
	{
		std::wstring s = buf;
		outFile << L"[ " << Time::GetDateTimeString() << L" ] " << s << std::endl;
		outFile.close();
		OutputDebugString(s.c_str());
	}
	else
	{
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}

	//MessageBox(0, LogDirectory().c_str(), 0, 0);
}

std::wstring Logger::LogDirectory()
{
	WCHAR path[1024];
	WCHAR* AppDataLocal;
	

	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);

	wcscpy_s(path, AppDataLocal);

	wcscat_s(path, L"\\");
	wcscat_s(path,PerGameSettings::GameName());
	CreateDirectory(path, NULL);
	wcscat_s(path, L"\\Log");
	CreateDirectory(path, NULL);
	return path;
}

std::wstring Logger::LogFile()
{
	WCHAR File[1024];
	wcscpy_s(File, PerGameSettings::GameName());
	wcscat_s(File, PerGameSettings::BootTime());
	wcscat_s(File, L".log");
	return File;
}

VOID Logger::PrintDebugSeperator()
{
	std::wstring s = L"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -";

#ifdef _DEBUG
	std::wfstream outFile;
	outFile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);
	if (outFile.is_open())
	{
		outFile << s << std::endl;
		outFile.close();
		OutputDebugString(s.c_str());
	}
	else
	{
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}

BOOL Logger::IsMTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
	{
		while (Process32Next(snapshot, &entry))
		{
			if (!_wcsicmp(entry.szExeFile, L"mTail.exe"))
				exists = true;
		}
	}
	CloseHandle(snapshot);
	return exists;
}

VOID Logger::StartMTail()
{
	if (IsMTailRunning())
	{
		Logger::PrintLog(L"MTail failed to start - already running");
		return;
	}
	Logger::PrintLog(L"Starting MTail...");
	WCHAR path[MAX_PATH];
	GetCurrentDirectoryW(MAX_PATH, path);
	std::wstring url = path + std::wstring(L"/mTail.exe");
	std::wstring params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}