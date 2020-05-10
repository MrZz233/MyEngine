#pragma once

#ifdef ENG_PLATFORM_WINDOWS

extern MyEngine::Application* MyEngine::CreatApplication();

int main(int argc,char** argv)
{
	MyEngine::Log::Init();
	ENG_CORE_WARN("Initialization success!");
	ENG_ClIENT_INFO("Hello Log!");
	auto app = MyEngine::CreatApplication();
	app->Run();
	delete app;

}
	
#endif