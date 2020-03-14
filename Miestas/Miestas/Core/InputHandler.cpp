#include "InputHandler.h"
#include "Logger/Logger.h"
#include "Core/Event/KeyboardEvents.h"
#include "Core/Event/WindowEvents.h"
#include "Game/Events/StateEvents.h"
#include "Game/Events/CameraEvents.h"
#include "Core/Event/AudioEvents.h"
#include "Core/KeyBindings.h"

namespace Miestas
{
	namespace Core
	{
		void InputHandler::init()
		{
			return;
		}


		void InputHandler::onEvent(std::shared_ptr<Event> event)
		{
			switch (event->m_eventType)
			{
			case EventType::GameStateChangeEvent:
			{
				auto e = STATIC_PTR_CAST(GameStateChangeEvent, event)
				handleGameStateChangeEvent(e);
				break;
			}

			case EventType::MouseMovedEvent:

				MIESTAS_LOG_INFO("Input Handler: Mouse Moved")
				break;

			case EventType::MouseButtonPressedEvent:
			{
				auto e = STATIC_PTR_CAST(MouseButtonPressedEvent, event)
				handleMouseButtonPressedEvent(e);
				break;
			}
			case EventType::KeyPressedEvent:

				auto e = STATIC_PTR_CAST(KeyPressedEvent, event)
					handleKeyPressedEvent(e);
				break;
			}
		}

		void InputHandler::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}

		void InputHandler::emitEvent(std::shared_ptr<Event> event)
		{
			m_eventQueue->addEventToQueue(std::move(event));
		}

		void InputHandler::handleGameStateChangeEvent(std::shared_ptr<GameStateChangeEvent> event)
		{
			//m_gameState = event->m_newGameState;
			MIESTAS_LOG_INFO("InputHandler: Received a GameStateChangeEvent.")
		}

		void InputHandler::handleKeyPressedEvent(std::shared_ptr<KeyPressedEvent> event)
		{
			//if (m_gameState != GameState::Playing)  // Keyboard is disable when not playing
			//	return;

			//switch (event->m_keyPressed)
			//{
			//case MIESTAS_KEY_ESCAPE:
			//{
			//	emitEvent(std::move(std::make_shared<GameStateChangeEvent>(GameState::MainMenu)));
			//	emitEvent(std::move(std::make_shared<PlaySoundEvent>("MainMenu", true)));
			//	break;
			//}

			//case MIESTAS_KEY_A:
			//{
			//	emitEvent(std::move(std::make_shared<CameraMoveEvent>(CameraMoveEvent::CameraMoveDirection::Left, 0.0f))); // Need to change 0.0f
			//	break;
			//}

			//case MIESTAS_KEY_D:
			//{
			//	emitEvent(std::move(std::make_shared<CameraMoveEvent>(CameraMoveEvent::CameraMoveDirection::Right, 0.0f))); // Need to change 0.0f
			//	break;
			//}

			//case MIESTAS_KEY_W:
			//{
			//	emitEvent(std::move(std::make_shared<CameraMoveEvent>(CameraMoveEvent::CameraMoveDirection::Forward, 0.0f))); // Need to change 0.0f
			//	break;
			//}

			//case MIESTAS_KEY_S:
			//{
			//	emitEvent(std::move(std::make_shared<CameraMoveEvent>(CameraMoveEvent::CameraMoveDirection::Backward, 0.0f))); // Need to change 0.0f
			//	break;
			//}

			//case MIESTAS_KEY_TAB:
			//{
			//	// TODO: Show city overview
			//}

			//}
		}


		void InputHandler::handleMouseButtonPressedEvent(std::shared_ptr<MouseButtonPressedEvent> event)
		{
			//emitEvent(std::move(std::make_shared<GameStateChangeEvent>(GameState::Playing)));
			//emitEvent(std::move(std::make_shared<StopSoundEvent>()));
		}
	}
}

