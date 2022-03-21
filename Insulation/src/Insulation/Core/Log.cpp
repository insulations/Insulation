#include "Ins_pch.h"
#include "Log.h"

namespace Insulation
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger; 
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		s_CoreLogger = spdlog::stdout_color_mt("Insulation");
		s_CoreLogger->set_level(spdlog::level::trace);
		
		s_ClientLogger = spdlog::stdout_color_mt("Application");
		s_ClientLogger->set_level(spdlog::level::trace);

		spdlog::set_pattern(*s_CoreLogger,"%^[%T] %n: %v%$");
		spdlog::set_pattern(*s_ClientLogger, "%^[%T] %n: %v%$");
	}
}