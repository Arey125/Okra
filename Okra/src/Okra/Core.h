#pragma once

#ifdef OKRA_BUILD_DLL
	#define OKRA_API __declspec(dllexport)
#else
	#define OKRA_API __declspec(dllimport)
#endif