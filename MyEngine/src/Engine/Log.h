#pragma once

#include"Core.h"
#include"spdlog/spdlog.h"
#include"spdlog/fmt/ostr.h"

namespace MyEngine {

	class MYENGINE_API Log
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

//Core Log macros
#define ENG_CORE_ERROR(...)		::MyEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENG_CORE_WARN(...)		::MyEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENG_CORE_INFO(...)		::MyEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENG_CORE_TRACE(...)		::MyEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ENG_CORE_FATAL(...)		::MyEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log macros
#define ENG_ClIENT_ERROR(...)	::MyEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENG_ClIENT_WARN(...)	::MyEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENG_ClIENT_INFO(...)	::MyEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENG_ClIENT_TRACE(...)	::MyEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ENG_ClIENT_FATAL(...)	::MyEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

