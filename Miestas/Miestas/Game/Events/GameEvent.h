#ifndef GAME_EVENTS_H
#define GAME_EVENTS_H

#include "Core/Event/Event.h"
#include "Game/State/GameState.h"

#define REGISTER_GAME_STATE(e) GameState m_gameState = GameState::##e;
#define GET_GAME_STATE(x) virtual GameState getGameState() const x { return m_gameState; }

namespace Miestas
{
	namespace Game
	{
		using namespace Miestas::Core;

		struct GameEvent : public Event
		{
			////REGISTER_TYPE(None)
			//REGISTER_CATEGORY(GameEvent)
			//REGISTER_GAME_STATE(None)

			//GET_TYPE(override)
			//GET_CATEGORY(override)
			//GET_GAME_STATE()
		};



	}
}

#endif