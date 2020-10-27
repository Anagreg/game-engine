#pragma once

#ifdef TG_PLATFORM_WINDOWS
	#ifdef TG_BUILD_DLL
		#define	TAMAGO_API __declspec(dllexport)
	#else
		#define	TAMAGO_API __declspec(dllimport)
	#endif 
#else
	#error Tamago only supports Windows!
#endif

#define BIT(x) (1 << x)