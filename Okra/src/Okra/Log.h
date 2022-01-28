#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace okra
{

	class OKRA_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};

}

//Core log macros
#define OKRA_CORE_TRACE(...)	::okra::Log::getCoreLogger()->trace(__VA_ARGS__)
#define OKRA_CORE_INFO(...)		::okra::Log::getCoreLogger()->info(__VA_ARGS__)
#define OKRA_CORE_WARN(...)		::okra::Log::getCoreLogger()->warn(__VA_ARGS__)
#define OKRA_CORE_ERROR(...)	::okra::Log::getCoreLogger()->error(__VA_ARGS__)

//Client log macros
#define OKRA_TRACE(...)			::okra::Log::getClientLogger()->trace(__VA_ARGS__)
#define OKRA_INFO(...)			::okra::Log::getClientLogger()->info(__VA_ARGS__)
#define OKRA_WARN(...)			::okra::Log::getClientLogger()->warn(__VA_ARGS__)
#define OKRA_ERROR(...)			::okra::Log::getClientLogger()->error(__VA_ARGS__)
