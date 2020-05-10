#pragma once

#ifdef ENG_PLATFORM_WINDOWS
	#ifdef ENG_BUILD_DLL
		#define MYENGINE_API __declspec(dllexport)
	#else
		#define MYENGINE_API __declspec(dllimport)
	#endif
#else
	#error MyEngine only supports Windows!
#endif

#ifdef ENG_ENABLE_ASSERTS
	#define ENG_CLIENT_ASSERT(x, ...) { if(!(x)) { ENG_ClIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ENG_CORE_ASSERT(x, ...) { if(!(x)) { ENG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ENG_CLIENT_ASSERT(x, ...)
	#define ENG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)