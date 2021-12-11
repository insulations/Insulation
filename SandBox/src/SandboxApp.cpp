#include <Insulation.h>

class Sandbox : public Insulation::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Insulation::Application* Insulation::CreateApplication()
{
	return new Sandbox();
}