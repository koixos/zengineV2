#pragma once

#ifdef ZN_PLATFORM_WINDOWS

extern Zengine::Application* Zengine::CreateApplication();

int main(int argc, char **argv)
{
	Zengine::Log::Init();

	ZN_CORE_INFO("Zengine Log Initialized!");
	int a = 5;
	ZN_WARN("Application Log Initialized!\nHello - var = {0}", a);

	auto app = Zengine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif