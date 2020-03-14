#include<memory>
#include<iostream>
#include<vector>

#include "Application.h"

#include "UI/UIElement.h"

using namespace Miestas;
using namespace Miestas::Core;
using namespace Miestas::Game;
using namespace Miestas::UI;

int main()
{
	std::unique_ptr<Application> m_Application = std::make_unique<Application>();
	m_Application->init();

	m_Application->run();
	
	/*std::vector<UIElement> elements;

	for (auto i = 0; i < 10; i++)
	{
		elements.emplace_back();
	}

	for (const auto& x : elements)
	{
		std::cout << x.m_Id << std::endl;
		x.onCallback();
	}*/

	std::cin.get();
}
