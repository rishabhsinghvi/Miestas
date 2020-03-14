#ifndef CAMERA_EVENTS_H
#define CAMERA_EVENTS_H

#include "GameEvent.h"

namespace Miestas
{
	namespace Game
	{
		struct CameraMoveEvent : public GameEvent
		{
			//enum class CameraMoveDirection
			//{
			//	Forward = 0,
			//	Backward,
			//	Left, 
			//	Right
			//};

			//REGISTER_TYPE(CameraMoveEvent)
			//REGISTER_CATEGORY(GameEvent)
			//REGISTER_GAME_STATE(None)

			//GET_TYPE(override)
			//GET_CATEGORY(override)
			//GET_GAME_STATE(override)

			//float m_deltaT;
			//CameraMoveDirection m_cameraMoveDirection;

			//// Don't really care about the state
			//CameraMoveEvent(CameraMoveDirection cameraDir, float dt) : m_cameraMoveDirection(cameraDir), m_deltaT(dt)
			//{}

			
		};

		struct CameraRotateEvent : public GameEvent
		{/*
			REGISTER_TYPE(CameraRotateEvent)
			REGISTER_CATEGORY(GameEvent)
			REGISTER_GAME_STATE(None)

			GET_TYPE(override)
			GET_CATEGORY(override)
			GET_GAME_STATE(override)

			float m_newX, m_newY;

			CameraRotateEvent(float newX, float newY) : m_newX(newX), m_newY(newY)
			{}*/
		};
	}
}


#endif