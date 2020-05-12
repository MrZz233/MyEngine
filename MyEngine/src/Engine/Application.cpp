#include "Engpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "GLFW/glfw3.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

namespace MyEngine {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		std::function<void(Event&)> callback = BIND_EVENT_FN(OnEvent);
		m_Window->SetEventCallback(callback);
		//相当于m_Window->m_Data.EventCallback = OnEvent;
		//m_Window是WindowsWindow类实体，是个单例，只有一个
		//m_Data是WindowData实体，用来描述当前Window信息
	}

	void Application::OnEvent(Event &e)
	{
		//ENG_CORE_INFO("Application_____:{0}",e);
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();	//当前layer的刷新
			m_Window->OnUpdate();	//glfw的一些刷新
		}
	}

}

