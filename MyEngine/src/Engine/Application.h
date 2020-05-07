#pragma once

#include "Core.h"

namespace MyEngine {

	class MYENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	
	Application* CreatApplication();

}


