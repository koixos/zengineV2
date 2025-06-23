#pragma once

#ifdef ZN_PLATFORM_WINDOWS
	#ifdef ZN_BUILD_DLL
		#define ZENGINE_API __declspec(dllexport)
	#else
		#define ZENGINE_API __declspec(dllimport)
	#endif
#else
	#error Zengine only supports Windows (for now)!
#endif

#ifdef ZN_ENABLE_ASSERTS
	#define ZN_ASSERT(x, ...) { if(!(x)) { ZN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ZN_CORE_ASSERT(x, ...) { if(!(x)) { ZN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ZN_ASSERT(x, ...)
	#define ZN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)