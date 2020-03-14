#include "EventQueue.h"
#include "Logger/Logger.h"

#include<algorithm>

namespace Miestas
{
	namespace Core
	{
		void EventQueue::registerObservable(EventType eventType, Observable * observable)
		{
			m_eventMap[eventType].push_back(observable);
			observable->setEventQueue(this);
		}

		void EventQueue::addEventToQueue(std::shared_ptr<Event> event)
		{
			m_nextFrameEventList.push_back(std::move(event));
		}


		void EventQueue::dispatchEvents()
		{
			std::swap(m_eventList, m_nextFrameEventList);

			if (m_eventList.size() == 0)
				return;

			for (auto& event : m_eventList)
			{
				auto type = event->m_eventType;
				auto observables = m_eventMap.find(type);

				if (observables == m_eventMap.end())
					continue;

				for (auto system : observables->second)
				{
					system->onEvent(event);
				}

			}

			m_eventList.clear();

		}


	}
}