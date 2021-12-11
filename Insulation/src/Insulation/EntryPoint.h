#pragma once

#ifdef INS_PLATFORM_WINDOWS

extern Insulation::Application* Insulation::CreateApplication();
int main(int argc, char** argv)
{
	auto app = Insulation::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // INS_PLATFORM_WINDOWS
