#pragma once

#ifdef ZN_PLATFORM_WINDOWS

extern Zengine::Application* Zengine::CreateApplication();

int main(int argc, char **argv)
{
	auto app = Zengine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif