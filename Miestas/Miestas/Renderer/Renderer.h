#ifndef RENDERER_H
#define RENDERER_H

#include<vector>
#include<memory>

#include "Scene.h"
#include "Managers/TextureManager.h"
#include "Managers/ShaderManager.h"
#include "Renderer/OrthoCamera.h"
#include "Core/Event/Event.h"
#include "Core/Event/EventQueue.h"
#include "Game/State/GameState.h"
#include "Game/Events/StateEvents.h"

/*
The main Renderer class. The class will contain a reference to camera objects, as well as all model data

Renderer->beginScene() will simply fetch the ProjectionView matrix from the camera class
Renderer->endScene() will update the view matrix of the camera with data coming from the input handler 
*/

namespace Miestas
{
	namespace Renderer
	{

		using namespace Miestas::Core;
		using namespace Miestas::Game;

		class Renderer: public Observable
		{
		private:
			
			std::unique_ptr<TextureManager> m_textureManager;
			std::unique_ptr<ShaderManager> m_shaderManager;
			std::unique_ptr<OrthoCamera> m_orthoCamera;

			std::unordered_map<GameState, std::unique_ptr<Scene>> m_sceneList;

			GameState m_gameState = GameState::MainMenu;


			EventQueue* m_eventQueue;

		public:
			
			void setDepthTesting(bool mode) const;

			void setWireframeMode(bool mode) const;

			void init();
			
			void render() const;

			virtual void onEvent(std::shared_ptr<Event> event) override;

			virtual void setEventQueue(EventQueue* eq) override;

			virtual void emitEvent(std::shared_ptr<Event> event) override;

		private:

			void handleGameStateChangeEvent(std::shared_ptr<GameStateChangeEvent> event);

		};
	}
}


#endif