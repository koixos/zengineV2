#include "Application.h"
#include "Events/WindowEvent.h"
#include "Log.h"

namespace Zengine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		ZN_TRACE(e);

		while (true);
	}
}