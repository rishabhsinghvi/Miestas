#ifndef STATE_EVENTS_H
#define STATE_EVENTS_H

#include "Game/Events/GameEvent.h"
#include "Game/State/GameState.h"

namespace Miestas
{
	namespace Game
	{
		struct GameStateChangeEvent : public GameEvent
		{
			/*REGISTER_TYPE(GameStateChangeEvent)
			REGISTER_CATEGORY(GameEvent)
			REGISTER_GAME_STATE(None)

			GET_TYPE(override)
			GET_CATEGORY(override)
			GET_GAME_STATE(override)

			GameState m_newGameState;

			GameStateChangeEvent(GameState newGameState) : m_newGameState(newGameState)
			{}*/
		};
	}
}

#endif