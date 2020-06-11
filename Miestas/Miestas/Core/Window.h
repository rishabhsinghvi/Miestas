#ifndef WINDOW_H
#define WINDOW_H

#include<string>
#include<unordered_map>

#include "Renderer/GLFW/glfw3.h"

#include "Core/Event/Observable.h"
#include "Core/Event/EventQueue.h"

namespace Miestas
{
	namespace Core
	{
		class Window: public Observable
		{
		private:
			std::string m_windowTitle;
			unsigned int m_Width;
			unsigned int m_Height;
			bool m_vSyncEnabled;
			bool m_isFullScreen;

			GLFWwindow* m_Window;
			EventQueue* m_eventQueue;

			std::unordered_map<std::string, GLFWcursor*> m_cursorMap;

		public:

			Window() : m_windowTitle("Miestas Debug"), m_Width(800), m_Height(600), m_Window(nullptr), m_vSyncEnabled(false), m_isFullScreen(false) {}

			Window(const std::string& wt, unsigned int mw = 800, unsigned int mh = 600, bool fullScreen = false):
				m_windowTitle(wt), m_Width(mw), m_Height(mh), m_vSyncEnabled(false), m_isFullScreen(fullScreen) {}

			~Window();

			void enableVSync();

			void disableVSync();

			void init();

			void clear(float r, float g, float b, float a = 1.0f);

			void update();

			bool shouldClose() const;

			virtual void onEvent(std::shared_ptr<Event> event) override;

			virtual void setEventQueue(EventQueue* eq) override;


		//private:

			virtual void emitEvent(std::shared_ptr<Event> event) override;


		};
	}
}


#endif