#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "LayerStack.h"

namespace MyEngine {

	class MYENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	
	Application* CreatApplication();

}


