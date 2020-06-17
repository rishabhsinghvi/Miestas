#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include<vector>
#include<unordered_map>

#include "Core/Event/Observable.h"
#include "Event.h"

namespace Miestas
{
	namespace Core
	{
		class EventQueue
		{
		private:
			std::vector<std::shared_ptr<Event>> m_eventList; // The event list is dispatched at the start of every frame
			std::vector<std::shared_ptr<Event>> m_nextFrameEventList; // Events to be dispatched at the start of next frame are inserted here, and the two queues are swapped at the start of every frame
			std::unordered_map<EventType, std::vector<Observable*>> m_eventMap;

		public:
			void RegisterObservable(EventType eventType, Observable* observable);

			void AddEventToQueue(std::shared_ptr<Event> event);

			void DispatchEvents();

		};
	}
}


#endif