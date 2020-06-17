#include "glad/glad.h"

#include "Window.h"
#include "Logger/Logger.h"
#include "Core/Event/WindowEvents.h"
#include "Core/Event/KeyboardEvents.h"
#include "Core/Event/MouseEvents.h"
#include "Core/KeyBindings.h"


namespace Miestas
{
	namespace Core
	{
		Window::~Window()
		{
			glfwDestroyWindow(m_Window);
			glfwTerminate();
		}

		void Window::enableVSync()
		{
			if (!m_Window)
				return;

			glfwSwapInterval(1);
			m_vSyncEnabled = true;
			MIESTAS_LOG_INFO("Window: VSync Enabled")
		}

		void Window::disableVSync()
		{
			if (!m_Window)
				return;

			glfwSwapInterval(0);
			m_vSyncEnabled = false;
			MIESTAS_LOG_INFO("Window: VSync Disabled")
		}

		void Window::init()
		{
			if (!glfwInit())
			{
				MIESTAS_FAILURE("Window: Failed to initialize GLFW.")
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

#ifdef DEBUG_BUILD
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
			if (m_isFullScreen)
			{
				auto mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
				m_Window = glfwCreateWindow(mode->width, mode->height, m_windowTitle.c_str(), glfwGetPrimaryMonitor(), nullptr);
			}
			else
			{
				m_Window = glfwCreateWindow(m_Width, m_Height, m_windowTitle.c_str(), nullptr, nullptr);
			}

			if (!m_Window)
			{
				MIESTAS_FAILURE("Window: Failed to create window.")
			}
			
			glfwMakeContextCurrent(m_Window);
			//TODO: Resize callback

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				MIESTAS_FAILURE("Window: Failed to initialize GLAD")
			}
			
			// Need to do this, since lambdas with captures cannot be converted into function pointers
			glfwSetWindowUserPointer(m_Window, this);
			
			// Set resize callback
			glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int newWidth, int newHeight)
			{
				auto thisWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
				glViewport(0, 0, newWidth, newHeight);
				
				thisWindow->emitEvent(std::move(std::make_shared<WindowResizeEvent>(newWidth, newHeight)));
			});

			// Set window close callback
			glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				MIESTAS_LOG_INFO("Close event called.")
				auto thisWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

				thisWindow->emitEvent(std::move(std::make_shared<WindowCloseEvent>()));
			});


			// Set mouse movement callback
			glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double newX, double newY)
			{
				auto thisWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

				thisWindow->emitEvent(std::move(std::make_shared<MouseMovedEvent>(static_cast<float>(newX), static_cast<float>(newY))));
			});

			// Set mouse button callbacks
			glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				auto thisWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
				
				if (action == GLFW_PRESS)
					thisWindow->emitEvent(std::make_shared<MouseButtonPressedEvent>(button));
				else if (action == GLFW_RELEASE)
					thisWindow->emitEvent(std::move(std::make_shared<MouseButtonReleasedEvent>(button)));

			});


			// Set mouse scroll callback
			glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double deltaX, double deltaY)
			{
				auto thisWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

				thisWindow->emitEvent(std::move(std::make_shared<MouseScrollEvent>(static_cast<float>(deltaX), static_cast<float>(deltaY))));
			});

			// Set keyboard input callback
			glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mode)
			{
				auto thisWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

				if (action == GLFW_PRESS)
					thisWindow->emitEvent(std::move(std::make_shared<KeyPressedEvent>(key)));
				else if (action == GLFW_REPEAT)
					thisWindow->emitEvent(std::move(std::make_shared<KeyPressedEvent>(key, true)));
				else if (action == GLFW_RELEASE)
					thisWindow->emitEvent(std::move(std::make_shared<KeyReleasedEvent>(key)));
			});
			

			
			MIESTAS_LOG_INFO("Window: Successfully created and initialized window.")

		}

		void Window::clear(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}

		bool Window::shouldClose() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		void Window::onEvent(std::shared_ptr<Event> event)
		{
			// TODO
		}

		void Window::setEventQueue(EventQueue * eq)
		{
			m_eventQueue = eq;
		}
		
		void Window::emitEvent(std::shared_ptr<Event> event)
		{
			m_eventQueue->AddEventToQueue(event);
		}


		

	}
}