#ifndef MOUSE_EVENTS_H
#define MOUSE_EVENTS_H

#include "Event.h"

#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		struct MouseMovedEvent : public Event
		{
			//REGISTER_TYPE(MouseMovedEvent);
			//REGISTER_CATEGORY(ApplicationEvent);

			float m_newX, m_newY;

			MouseMovedEvent(float newX, float newY):
				REGISTER_EVENT_INFO(MouseMovedEvent, ApplicationEvent),
				m_newX(newX), m_newY(newY) {  }

			//GET_TYPE(override)
			//GET_CATEGORY(override)

		};

		struct MouseScrollEvent : public Event
		{
			//REGISTER_TYPE(MouseScrollEvent);
			//REGISTER_CATEGORY(ApplicationEvent);

			float m_deltaX, m_deltaY;

			MouseScrollEvent(float deltaX, float deltaY) :
				REGISTER_EVENT_INFO(MouseScrollEvent, ApplicationEvent), 
				m_deltaX(deltaX), m_deltaY(deltaY) {  }

			//GET_TYPE(override)
			//GET_CATEGORY(override)

		};

		struct MouseButtonPressedEvent : public Event
		{
			//REGISTER_TYPE(MouseButtonPressedEvent);
			//REGISTER_CATEGORY(ApplicationEvent);

			int m_buttonPressed;

			MouseButtonPressedEvent(int buttonPressed):
				REGISTER_EVENT_INFO(MouseButtonPressedEvent, ApplicationEvent), 
				m_buttonPressed(buttonPressed) {  }

			//GET_TYPE(override)
			//GET_CATEGORY(override)

		};

		struct MouseButtonReleasedEvent : public Event
		{
			//REGISTER_TYPE(MouseButtonReleasedEvent);
			//REGISTER_CATEGORY(ApplicationEvent);

			int m_buttonReleased;

			MouseButtonReleasedEvent(int buttonReleased): 
				REGISTER_EVENT_INFO(MouseButtonReleasedEvent, ApplicationEvent),
				m_buttonReleased(buttonReleased) {  }

			//GET_TYPE(override)
			//GET_CATEGORY(override)
		};
	}
}

#endif