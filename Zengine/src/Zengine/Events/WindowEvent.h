#pragma once

#include <sstream>

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

		EVENT_CLASS_CATEGORY(EventCategoryWindow)
		EVENT_CLASS_TYPE(WindowResize)
	private:
		unsigned int m_Width, m_Height;
	};

	class ZENGINE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() { }

		EVENT_CLASS_CATEGORY(EventCategoryWindow)
		EVENT_CLASS_TYPE(WindowClose)
	};
}