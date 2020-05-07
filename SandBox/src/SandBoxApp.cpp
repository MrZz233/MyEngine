#include "Engine.h"

class SandBox : public MyEngine::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}

};

MyEngine::Application* MyEngine::CreatApplication()
{
	return new SandBox();
}