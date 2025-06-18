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

#define BIT(x) (1 << x)