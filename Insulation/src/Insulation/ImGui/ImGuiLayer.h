#pragma once

#include "Insulation/Core/Layer.h"
#include "Insulation/Event/MouseEvent.h"
#include "Insulation/Event/KeyEvent.h"
#include "Insulation/Event/ApplicationEvent.h"

#include "Platform/OpenGL/imgui_impl_opengl3.h"

namespace Insulation
{
	class ImGuiLayer:public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnUpdate() override;		
		void OnEvent(Insulation::Event& e) override;		
		void OnAttach() override;
		void OnDetach() override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMoveEvent(MouseMoveEvent& e);
		bool OnMouseScrollEvent(MouseScrollEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);


	private:
		float m_Time = 0.0f;

	};
}


