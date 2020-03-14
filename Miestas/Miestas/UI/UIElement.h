#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include<functional>

namespace Miestas
{
	namespace UI
	{
		class UIElement
		{
		public:
			static unsigned int ID;

			float m_X;
			float m_Y;

			float m_Width;
			float m_Height;

			float m_Id;

			std::function<void()> m_Callback;

		public:

			UIElement() : m_Id(ID)
			{
				ID++;
			}

			UIElement(float x, float y, float width, float height) :
				m_X(x), m_Y(y), m_Width(width), m_Height(height), m_Id(ID)
			{
				ID++;
			}

			void onCallback() const;


		};

	}
}

#endif