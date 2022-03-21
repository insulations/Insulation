#include <Insulation.h>

class ExampleLayer : public Insulation::Layer
{
public:
	ExampleLayer() : Layer("Example"){}
	~ExampleLayer(){}

	void OnUpdate() override
	{
		INS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Insulation::Event& e) override
	{
		INS_TRACE("{0}", e);
	}

	void OnAttach() override
	{

	}
	void OnDetach() override
	{

	}

};

class Sandbox : public Insulation::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Insulation::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Insulation::Application* Insulation::CreateApplication()
{
	return new Sandbox();
}