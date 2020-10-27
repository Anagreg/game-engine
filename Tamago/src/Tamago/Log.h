#pragma once

#include<memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Tamago {

	class TAMAGO_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};

}

//Core Log Macros
#define TG_CORE_TRACE(...)     ::Tamago::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TG_CORE_INFO(...)      ::Tamago::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TG_CORE_WARN(...)      ::Tamago::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TG_CORE_ERROR(...)     ::Tamago::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TG_CORE_CRITICAL(...)     ::Tamago::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client Log Macros
#define TG_CLIENT_TRACE(...)   ::Tamago::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TG_CLIENT_INFO(...)    ::Tamago::Log::GetClientLogger()->info(__VA_ARGS__)
#define TG_CLIENT_WARN(...)    ::Tamago::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TG_CLIENT_ERROR(...)   ::Tamago::Log::GetClientLogger()->error(__VA_ARGS__)
#define TG_CLIENT_CRITICAL(...)   ::Tamago::Log::GetClientLogger()->critical(__VA_ARGS__)

