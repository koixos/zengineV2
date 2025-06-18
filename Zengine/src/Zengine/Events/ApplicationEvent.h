#pragma once

#include <sstream>

#include "Event.h"

namespace Zengine
{
	class ZENGINE_API ApplicationEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ZENGINE_API AppTickEvent : public ApplicationEvent
	{
	public:
		AppTickEvent() : ApplicationEvent() { }

		EVENT_CLASS_TYPE(AppTick)
	};

	class ZENGINE_API AppUpdateEvent : public ApplicationEvent
	{
	public:
		AppUpdateEvent() : ApplicationEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
	};

	class ZENGINE_API AppRenderEvent : public ApplicationEvent
	{
	public:
		AppRenderEvent() : ApplicationEvent() {}

		EVENT_CLASS_TYPE(AppRender)
	};
}