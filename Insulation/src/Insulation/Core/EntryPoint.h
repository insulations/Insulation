#pragma once

#ifdef INS_PLATFORM_WINDOWS

extern Insulation::Application* Insulation::CreateApplication();
int main(int argc, char** argv)
{
	Insulation::Log::Init();
	//Insulation::Log::GetCoreLogger()->warn("Initlized Core Log!");
	//Insulation::Log::GetClientLogger()->info("GOOD!");
	auto app = Insulation::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // INS_PLATFORM_WINDOWS
