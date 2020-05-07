#pragma once

#ifdef ENG_PLATFORM_WINDOWS

extern MyEngine::Application* MyEngine::CreatApplication();

int main(int argc,char** argv)
{

	printf("Welcome to MyEngine!\n");
	auto app = MyEngine::CreatApplication();
	app->Run();
	delete app;

}
	
#endif