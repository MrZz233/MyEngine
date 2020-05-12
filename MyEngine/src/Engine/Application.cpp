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
		//�൱��m_Window->m_Data.EventCallback = OnEvent;
		//m_Window��WindowsWindow��ʵ�壬�Ǹ�������ֻ��һ��
		//m_Data��WindowDataʵ�壬����������ǰWindow��Ϣ
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
				layer->OnUpdate();	//��ǰlayer��ˢ��
			m_Window->OnUpdate();	//glfw��һЩˢ��
		}
	}

}

