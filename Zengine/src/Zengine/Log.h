#pragma once

#include <memory>

#include "Core.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace Zengine
{
	class ZENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ZN_CORE_TRACE(...)  ::Zengine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZN_CORE_INFO(...)	::Zengine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZN_CORE_WARN(...)	::Zengine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZN_CORE_ERROR(...)	::Zengine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZN_CORE_FATAL(...)	::Zengine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define ZN_TRACE(...)   ::Zengine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZN_INFO(...)	::Zengine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZN_WARN(...)	::Zengine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZN_ERROR(...)	::Zengine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZN_FATAL(...)	::Zengine::Log::GetClientLogger()->fatal(__VA_ARGS__)
