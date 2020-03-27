#include "Application.h"
#include "Logger/Logger.h"

#include "Core/Event/AudioEvents.h"
#include "Core/Event/KeyboardEvents.h"

#define REGISTER_OBSERVABLE(x,y) m_appEventQueue->registerObservable(EventType::##x, y##.get());
#define REGISTER_OBSERVABLE_THIS(x) m_appEventQueue->registerObservable(EventType::##x, this);

namespace Miestas
{
	using namespace Miestas::Renderer;
	
	Application::~Application()
	{
		this->destroy();
	}

	void Application::init()
	{
		// Read Config from file
		m_Config = std::make_unique<Config>();
		m_Config->init("../Miestas/Resources/Configs/Config.json");

		// Initialize all the systems
		m_Window = std::make_unique<Window>(m_Config->m_applicationName, m_Config->m_windowWidth, m_Config->m_windowHeight, m_Config->m_isFullScreen);
		m_Renderer = std::make_unique<MiestasRenderer>();
		m_inputHandler = std::make_unique<InputHandler>();
		m_gameManager = std::make_unique<GameManager>();
		m_soundLibrary = std::make_unique<SoundLibrary>();


		// Initialize m_eventQueue at the end after all the systems have been initialized
		// And then register each event with m_eventQueue
		m_appEventQueue = std::make_unique<EventQueue>();


		m_Window->init();
		m_Renderer->init();
		m_inputHandler->init();
		m_soundLibrary->init();
		m_gameManager->init(m_Config->m_cityConfig);

		// Remove later
		m_soundLibrary->addSongToLibrary("MainMenu", "../Miestas/Resources/Sounds/MainMenu.wav");
		
		// Register None Type Event
		REGISTER_OBSERVABLE(None, m_Window)
		REGISTER_OBSERVABLE(None, m_Renderer)
		REGISTER_OBSERVABLE(None, m_gameManager)
		
		// Register Key Pressed Events
		REGISTER_OBSERVABLE(KeyPressedEvent, m_inputHandler)
		REGISTER_OBSERVABLE(KeyReleasedEvent, m_inputHandler)

		
		// Register Mouse Pressed Events
		REGISTER_OBSERVABLE(MouseButtonPressedEvent, m_inputHandler)
		
		// Register Game State Change Event

		//REGISTER_OBSERVABLE(GameStateChangeEvent, m_gameManager)
		REGISTER_OBSERVABLE(GameStateChangeEvent, m_inputHandler)
		REGISTER_OBSERVABLE(GameStateChangeEvent, m_Renderer)


		// Register Window Resize Event
		REGISTER_OBSERVABLE_THIS(WindowResizeEvent)
		
		// Register Window Close Event
		REGISTER_OBSERVABLE_THIS(WindowCloseEvent)

		// Register Sound Play Event
		REGISTER_OBSERVABLE(PlaySoundEvent, m_soundLibrary)

		// Register Sound Stop Event
		REGISTER_OBSERVABLE(StopSoundEvent, m_soundLibrary)
		
		m_gameManager->setGameState(GameState::MainMenu);
		//emitEvent(std::move(std::make_shared<PlaySoundEvent>("MainMenu", true)));
	}


	

	void Application::run()
	{
		while (m_isRunning)
		{
			m_appEventQueue->dispatchEvents();
			m_Window->clear(0.5f, 0.6f, 0.8f, 1.0f);
			m_Renderer->render();
			m_Window->update();
		}
	}

	void Application::close()
	{
		destroy();
	}

	void Application::onEvent(std::shared_ptr<Event> event)
	{
		switch (event->m_eventType)
		{
		case EventType::WindowCloseEvent:
		{
			m_isRunning = false;
			break;
		}
		case EventType::WindowResizeEvent:
			// Do nothing
			break;

		default:
			break;
		}
	}

	void Application::setEventQueue(EventQueue * eq)
	{
		m_eventQueue = eq;
	}

	void Application::destroy()
	{
		// TODO: Make sure we destroy in reverse order
	}

	void Application::emitEvent(std::shared_ptr<Event> event)
	{
		m_eventQueue->addEventToQueue(event);
	}








}
