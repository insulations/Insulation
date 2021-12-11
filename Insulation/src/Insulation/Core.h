#pragma once

#ifdef INS_PLATFORM_WINDOWS
	#ifdef INS_BUILD_DLL
		#define INS_API __declspec(dllexport)
	#else
		#define INS_API __declspec(dllimport)
	#endif // INS_BUILD_DLL
#else
	#error Insulation only support windows now!
#endif // INS_PLATFORM_WINDOWS
