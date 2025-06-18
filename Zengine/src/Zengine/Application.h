#pragma once

#include "Core.h"

namespace Zengine
{
	class ZENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined in CLIENT
	Application* CreateApplication();
}

