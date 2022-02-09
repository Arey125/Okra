#pragma once

#ifdef OKRA_BUILD_DLL
	#define OKRA_API __declspec(dllexport)
#else
	#define OKRA_API __declspec(dllimport)
#endif

#ifdef OKRA_DEBUG
	#define OKRA_ENABLE_ASSERTS
#endif

#ifdef OKRA_ENABLE_ASSERTS
	#define OKRA_ASSERT(x, ...) if (!(x)) {OKRA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}
	#define OKRA_CORE_ASSERT(x, ...) if (!(x)) {OKRA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}
#else
	#define OKRA_ASSERT(x, ...)
	#define OKRA_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)