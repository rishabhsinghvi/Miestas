#ifndef EVENT_H
#define EVENT_H

//#define REGISTER_TYPE(e) m_eventType = EventType::##e
//#define REGISTER_CATEGORY(e) m_eventCategory = EventCategory::##e
//#define GET_TYPE(x) virtual EventType getType() const x { return m_eventType; }
//#define GET_CATEGORY(x) virtual EventCategory getCategory() const x { return m_eventCategory; }


#define REGISTER_EVENT_INFO(x,y) Event(EventType::##x, EventCategory::##y)

namespace Miestas
{
	namespace Core
	{
		enum class EventCategory
		{
			None = 0,
			GameEvent,
			ApplicationEvent
		};


		enum class EventType
		{
			None = 0,

			// Application Events
			WindowResizeEvent, WindowCloseEvent,
			KeyPressedEvent, KeyReleasedEvent,
			MouseMovedEvent, MouseScrollEvent, MouseButtonPressedEvent, MouseButtonReleasedEvent,
			PlaySoundEvent, StopSoundEvent,

			// Game Events
			GameStateChangeEvent,
			CameraMoveEvent, CameraRotateEvent
		};

		
		struct Event
		{
			EventType m_eventType = EventType::None;
			EventCategory m_eventCategory = EventCategory::None;

			Event(EventType etype, EventCategory ecat) :
				m_eventType(etype), m_eventCategory(ecat)
			{
			}
			//REGISTER_TYPE(None)
			//REGISTER_CATEGORY(None)
			//GET_TYPE()
			//GET_CATEGORY()
		};


	}
}

#endif