#pragma once

#include "Event.h"

namespace Zengine
{
	class ZENGINE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int w, unsigned int h)
			: m_Width(w), m_Height(h) {
		}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << " x " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int m_Width, m_Height;
	};

	class ZENGINE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

	class ZENGINE_API AppEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ZENGINE_API AppTickEvent : public AppEvent
	{
	public:
		AppTickEvent() : AppEvent() { }

		EVENT_CLASS_TYPE(AppTick)
	};

	class ZENGINE_API AppUpdateEvent : public AppEvent
	{
	public:
		AppUpdateEvent() : AppEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
	};

	class ZENGINE_API AppRenderEvent : public AppEvent
	{
	public:
		AppRenderEvent() : AppEvent() {}

		EVENT_CLASS_TYPE(AppRender)
	};
}