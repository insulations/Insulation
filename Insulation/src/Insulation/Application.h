#pragma once
#include "Core.h"

namespace Insulation
{
	class INS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}


