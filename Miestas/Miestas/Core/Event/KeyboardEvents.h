#ifndef KEYBOARD_EVENTS_H
#define KEYBOARD_EVENTS_H

#include "Event.h"

#include "Core/KeyBindings.h"
#include "Logger/Logger.h"

namespace Miestas
{
	namespace Core
	{
		struct KeyPressedEvent : public Event
		{
			//REGISTER_TYPE(KeyPressedEvent);
			//REGISTER_CATEGORY(ApplicationEvent);

			int m_keyPressed;
			bool m_isRepeated;

			KeyPressedEvent(int keyPressed, bool isRepeated = false) :
				REGISTER_EVENT_INFO(KeyPressedEvent, ApplicationEvent),
				m_keyPressed(keyPressed), m_isRepeated(isRepeated) {  }

			//GET_TYPE(override)
			//GET_CATEGORY(override)
		};

		struct KeyReleasedEvent : public Event
		{/*
			REGISTER_TYPE(KeyReleasedEvent);
			REGISTER_CATEGORY(ApplicationEvent);*/

			int m_keyReleased;

			KeyReleasedEvent(int keyReleased) :
				REGISTER_EVENT_INFO(KeyReleasedEvent, ApplicationEvent),
				m_keyReleased(keyReleased) {  }

			//GET_TYPE(override)
			//GET_CATEGORY(override)

		};
	}
}
#endif