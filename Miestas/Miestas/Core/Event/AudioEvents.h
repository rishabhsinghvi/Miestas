#ifndef AUDIO_EVENTS_H
#define AUDIO_EVENTS_H

#include "Event.h"

#include<string>


namespace Miestas
{
	namespace Core
	{
		struct PlaySoundEvent : public Event
		{
			//REGISTER_TYPE(PlaySoundEvent);
			//REGISTER_CATEGORY(ApplicationEvent);

			std::string m_soundToPlay;
			bool m_Looped;

			PlaySoundEvent(const std::string& soundToPlay, bool looped = false) :
				REGISTER_EVENT_INFO(PlaySoundEvent, ApplicationEvent),
				m_soundToPlay(soundToPlay), m_Looped(looped)
			{}

			PlaySoundEvent(std::string&& soundToPlay, bool looped = false) :
				REGISTER_EVENT_INFO(PlaySoundEvent, ApplicationEvent),
				m_soundToPlay(std::move(soundToPlay)), m_Looped(looped)
			{}/*

			GET_TYPE(override)
			GET_CATEGORY(override)*/

		};

		struct StopSoundEvent : public Event
		{/*
			REGISTER_TYPE(StopSoundEvent);
			REGISTER_CATEGORY(ApplicationEvent);*/

			StopSoundEvent():
				REGISTER_EVENT_INFO(StopSoundEvent, ApplicationEvent)
			{}



			/*GET_TYPE(override)
			GET_CATEGORY(override)*/

		};
	}
}

#endif