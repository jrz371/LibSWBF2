#include "stdafx.h"
#include "API.h"

namespace LibSWBF2::API
{
	// Logging //
	LIBSWBF2_API void LOG_SetCallbackMethod(LogCallback* Callback)
	{
		if (!Callback)
		{
			LOG("[API] Given Callback function pointer was NULL!", ELogType::Warning);
			return;
		}

		Logger::SetLogCallback(*Callback);
	}


	// MSH //
	LIBSWBF2_API MSH* MSH_Create()
	{
		return MSH::Create();
	}

	LIBSWBF2_API void MSH_Delete(MSH* msh)
	{
		return MSH::Destroy(msh);
	}

	LIBSWBF2_API void MSH_ReadFromFile(MSH* msh, const char* path)
	{
		if (!msh)
		{
			LOG("[API] Given MSH pointer was NULL!", ELogType::Error);
			return;
		}

		msh->ReadFromFile(string(path));
	}
}