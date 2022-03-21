#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/pattern_formatter.h"
#include "spdlog/fmt/ostr.h"

namespace Insulation
{
	class Log
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
#define INS_CORE_TRACE(...)    ::Insulation::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define INS_CORE_INFO(...)     ::Insulation::Log::GetCoreLogger()->info(__VA_ARGS__)
#define INS_CORE_WARN(...)     ::Insulation::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define INS_CORE_ERROR(...)    ::Insulation::Log::GetCoreLogger()->error(__VA_ARGS__)
#define INS_CORE_CRITICAL(...) ::Insulation::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define INS_TRACE(...)         ::Insulation::Log::GetClientLogger()->trace(__VA_ARGS__)
#define INS_INFO(...)          ::Insulation::Log::GetClientLogger()->info(__VA_ARGS__)
#define INS_WARN(...)          ::Insulation::Log::GetClientLogger()->warn(__VA_ARGS__)
#define INS_ERROR(...)         ::Insulation::Log::GetClientLogger()->error(__VA_ARGS__)
#define INS_CRITICAL(...)      ::Insulation::Log::GetClientLogger()->critical(__VA_ARGS__)

