#include "Renderer.h"
#include "Logger/Logger.h"
#include "Game/Events/StateEvents.h"
#include "Game/Events/CameraEvents.h"
#include "AttributeLayout.h"

#include "glad/glad.h"

#include<vector>
#include<unordered_map>

#include<iostream>

namespace Miestas
{
	namespace Renderer
	{
		
		void Renderer::setDepthTesting(bool mode) const
		{
			if (mode)
			{
				glEnable(GL_DEPTH_TEST);
			}
			else
			{
				glDisable(GL_DEPTH_TEST);
			}
		}

		void Renderer::setWireframeMode(bool mode) const
		{
			if (mode)
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else
			{
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}

		}

		void Renderer::init()
		{
			m_textureManager = std::make_unique<TextureManager>();
			m_shaderManager = std::make_unique<ShaderManager>();
			m_orthoCamera = std::make_unique<OrthoCamera>(-400.0f, 400.0f, 0.01f, 100.0f); // for now

			// Need to remove this
			m_textureManager->loadTexture("MainMenu", "../Miestas/Resources/Images/BackgroundImageMainMenu.png", aiTextureType_NONE);
			m_shaderManager->loadShader("MainMenu", "../Miestas/Resources/Shaders/MainMenu.vs", "../Miestas/Resources/Shaders/MainMenu.fs");

			// Setting up Main Menu quad vertices - should this be in a config?
			std::vector<float> vertices = {
				1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
				1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
				-1.0f, -1.0f, 0.0f,0.0f, 0.0f,
				-1.0f, 1.0f, 0.0f, 0.0f, 1.0f
			};

			std::vector<unsigned int> indices = {  
				0, 1, 3,   // first triangle
				1, 2, 3    // second triangle
			};

			auto vertexArray = std::make_unique<VertexArray>();
			std::vector<AttributeLayout> attributeLayout = { {3, GL_FLOAT, false}, {2, GL_FLOAT, false} };
			auto vertexBuffer = std::make_unique<VertexBuffer>(std::move(vertices), std::move(attributeLayout));
			auto indexBuffer = std::make_unique<IndexBuffer>(std::move(indices));
			vertexArray->bindVertexBuffer(std::move(vertexBuffer));
			vertexArray->bindIndexBuffer(std::move(indexBuffer));

			auto sceneObject = std::make_unique<SceneObject>(std::move(vertexArray), "MainMenu", "MainMenu", 1);

			auto mainMenuScene = std::make_unique<Scene>();
			mainMenuScene->addSceneObject(std::move(sceneObject));

			m_sceneList[GameState::MainMenu] = std::move(mainMenuScene);
			
			MIESTAS_LOG_INFO("Renderer: Successfully initiliazed Renderer")
		}


		void Renderer::render() const
		{
			const auto& scene = m_sceneList.find(m_gameState);

			if (scene == m_sceneList.end())
				return;


			auto m_viewProjectionMatrix = m_orthoCamera->getViewProjection();

			if (m_gameState == GameState::MainMenu || m_gameState == GameState::Paused)
			{
				setDepthTesting(false);
			}
			else
			{
				setDepthTesting(true);
			}


			for (const auto& object : scene->second->getSceneObjects())
			{
				const auto& vertexArray = object->m_vertexArray;
				
				vertexArray->bind();
				m_shaderManager->getShader(object->m_shaderName)->bind();
				m_textureManager->getTexture(object->m_textureName)->bind();
				
				m_shaderManager->getShader(object->m_shaderName)->setUniformInt("texture1", 0);
				// TODO: instanced rendering

				glDrawElements(GL_TRIANGLES, vertexArray->getNumIndices(), GL_UNSIGNED_INT, 0);
			}

		}

		void Renderer::onEvent(std::shared_ptr<Event> event)
		{
			// Receives transformations from the game state and applies to objects (?)

			switch (event->m_eventType)
			{
			case EventType::GameStateChangeEvent:
			{
				auto e = STATIC_PTR_CAST(GameStateChangeEvent, event)
				handleGameStateChangeEvent(e);
				break;
			}
			}

		}

		void Renderer::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}

		void Renderer::emitEvent(std::shared_ptr<Event> event)
		{
			m_eventQueue->addEventToQueue(std::move(event));
		}

		

		void Renderer::handleGameStateChangeEvent(std::shared_ptr<GameStateChangeEvent> event)
		{
			//m_gameState = event->m_newGameState;
			MIESTAS_LOG_INFO("Renderer: Received a GameStateChangedEvent.")
		}
	} 
}