#include "GameManager.h"
#include "Logger/Logger.h"
#include "Game/Events/StateEvents.h"
#include "Core/Event/AudioEvents.h"

#include "json/json.hpp"

#include<fstream>

namespace Miestas
{
	namespace Game
	{
		void GameManager::init(const std::string& configFilePath)
		{
			m_cityManager = std::make_unique<CityManager>();
			

			//m_cityManager->init(configFilePath);


			m_isInitialized = true;
			MIESTAS_LOG_INFO("GameManager: Successfully initialized.")
		}

		void GameManager::onEvent(std::shared_ptr<Event> event)
		{
			// TODO
			/*switch (event->getType())
			{
			case EventType::GameStateChangeEvent:
			{
				auto e = STATIC_PTR_CAST(GameStateChangeEvent, event)
				if (e->m_newGameState == m_stateManager->m_currentState)
					return;

				m_stateManager->m_currentState = e->m_newGameState;
				break;
			}
			}*/
		}
		void GameManager::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}

		void GameManager::emitEvent(std::shared_ptr<Event> event)
		{
			m_eventQueue->addEventToQueue(event);
		}

		void GameManager::saveGameData()
		{
			// TODO
		}

		GameState GameManager::getGameState() const
		{
			return m_gameState;
		}

		void GameManager::setGameState(GameState gameState)
		{
			if (m_gameState == gameState)
				return;

			m_gameState = gameState;

			//emitEvent(std::move(std::make_shared<GameStateChangeEvent>(gameState)));
			
			if (gameState == GameState::MainMenu)
			{
				emitEvent(std::move(std::make_shared<PlaySoundEvent>("MainMenu", true)));
			}
		}


	}
}