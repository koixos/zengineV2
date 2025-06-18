#include "Application.h"
#include "Zengine/Events/ApplicationEvent.h"
#include "Zengine/Log.h"

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