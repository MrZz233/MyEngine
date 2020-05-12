#include "Engine.h"

class ExampleLayer:public MyEngine::Layer
{
public:
	ExampleLayer():Layer("Example"){}

	void OnUpdate() override
	{
		if (count > 60)
		{
			ENG_ClIENT_INFO("ExampleLayer__________Update");
			count = 0;
		}
		count++;
	}

	void OnEvent(MyEngine::Event& event)override
	{
		ENG_ClIENT_TRACE("Layer____{0}",event);
	}

private:
	int count = 0;
};

class SandBox : public MyEngine::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox()
	{

	}

};

MyEngine::Application* MyEngine::CreatApplication()
{
	return new SandBox();
}