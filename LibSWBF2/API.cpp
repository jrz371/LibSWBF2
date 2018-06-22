#include "stdafx.h"
#include "API.h"
#include "Color.h"
#include "Logger.h"

namespace LibSWBF2
{
	LIBSWBF2_API MSH* MSH_LoadFromFile(const char* path)
	{
		return new MSH();
	}

	LIBSWBF2_API void MSH_Delete(MSH* ptr)
	{
		delete ptr;
	}

	// Logging //
	LIBSWBF2_API void AddLogMessage(const char* message, const ELogType logType)
	{
		Logger::Add("[API] " + string(message), logType);
	}

	LIBSWBF2_API void GetLogMessages(char* messages, const int length, const ELogType logType)
	{
		strcpy_s(messages, length, Logger::GetAllLines(logType).c_str());
	}

	LIBSWBF2_API void GetLastLogMessages(char* messages, const int length, const ELogType logType)
	{
		strcpy_s(messages, length, Logger::GetLastLines(logType).c_str());
	}
}