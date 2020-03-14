#include "SoundLibrary.h"
#include "Logger/Logger.h"
#include "Core/Event/EventQueue.h"
#include "Core/Event/AudioEvents.h"

#include "json/json.hpp"

#include<fstream>

#define STRING_TO_LOWER(x) std::transform(x.##begin(), x.##end(), x.##begin(), [](unsigned char ch){ return std::tolower(ch); });

namespace Miestas
{
	namespace Core
	{

		SoundLibrary::~SoundLibrary()
		{
			destroy();
		}
		
		// TODO: Read from config file
		void SoundLibrary::init()
		{
			m_Engine = irrklang::createIrrKlangDevice();
			
			if (!m_Engine)
			{
				MIESTAS_FAILURE("SoundLibrary: Unable to initialize SoundEngine.")
			}

			

			MIESTAS_LOG_INFO("SoundLibrary: Successfully initialized.")
		}

		void SoundLibrary::playSound(const std::string & sound, bool looped)
		{
			STRING_TO_LOWER(const_cast<std::string&>(sound))

			auto soundFile = m_Sounds.find(sound);
			if (soundFile == m_Sounds.end())
			{
				MIESTAS_LOG_ERROR("SoundLibrary: Unable to play sound: {0}.", sound)
				return;
			}

			m_Engine->play2D(soundFile->second.c_str(), looped);

		}

		void SoundLibrary::stopSound()
		{
			m_Engine->stopAllSounds();
		}

		void SoundLibrary::addSongToLibrary(const std::string & soundName, const std::string & soundFile)
		{
			STRING_TO_LOWER(const_cast<std::string&>(soundName))
			m_Sounds[soundName] = soundFile;
		}

		void SoundLibrary::destroy()
		{
			m_Engine->drop();
		}

		void SoundLibrary::onEvent(std::shared_ptr<Event> event)
		{
			switch (event->m_eventType)
			{
			case EventType::PlaySoundEvent:
			{
				auto e = STATIC_PTR_CAST(PlaySoundEvent, event)
				playSound(e->m_soundToPlay, e->m_Looped);
				break;
			}
			case EventType::StopSoundEvent:
			{
				stopSound();
				break;
			}
			}
		}

		void SoundLibrary::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}

		void SoundLibrary::emitEvent(std::shared_ptr<Event> event)
		{
			m_eventQueue->addEventToQueue(std::move(event));
		}
	}
}