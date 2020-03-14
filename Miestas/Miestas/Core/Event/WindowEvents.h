#ifndef WINDOW_EVENTS_H
#define WINDOW_EVENTS_H

#include "Event.h"

#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		struct WindowResizeEvent : public Event
		{
			//REGISTER_TYPE(WindowResizeEvent);
			//REGISTER_CATEGORY(ApplicationEvent);

			unsigned int m_newWidth, m_newHeight;

			WindowResizeEvent(unsigned int newWidth, unsigned int newHeight) : 
				REGISTER_EVENT_INFO(WindowResizeEvent, ApplicationEvent), 
				m_newWidth(newWidth), m_newHeight(newHeight) {  }

			//GET_TYPE(override)
			//GET_CATEGORY(override)
		};

		struct WindowCloseEvent : public Event
		{
			//REGISTER_TYPE(WindowCloseEvent);
			//REGISTER_CATEGORY(ApplicationEvent);

			WindowCloseEvent():
				REGISTER_EVENT_INFO(WindowCloseEvent, ApplicationEvent)
			{}

			//GET_TYPE(override)
			//GET_CATEGORY(override)
		};
	}
}

#endif
