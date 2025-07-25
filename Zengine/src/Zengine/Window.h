#pragma once

#include "znpch.h"
#include "Zengine/Core.h"
#include "Zengine/Events/Event.h"

namespace Zengine
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(
			const std::string& title = "Zengine",
			unsigned int width = 1280,
			unsigned int height = 720
		) : Title(title), Width(width), Height(height) { }
	};

	class ZENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}
		
		virtual void OnUpdate() = 0;
		
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		
		// To be implemented by the platform-specific window
		static Window* Create(const WindowProps& props = WindowProps());
	};
}