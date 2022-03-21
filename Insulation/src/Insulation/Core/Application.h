#pragma once
#include "Core.h"
#include "Window.h"
#include "Insulation/Event/ApplicationEvent.h"
#include "LayerStack.h"


namespace Insulation
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlayer);

		inline static Application& Get() { return *s_instance; }
		inline Window& GetWindow() { return *m_Window; }
	protected:
		std::unique_ptr<Window> m_Window;
		bool m_running = true;
		LayerStack m_LayerStack;

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		static Application* s_instance;
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}


