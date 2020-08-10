#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include <iostream>
//void FixConsoleWindow() {
//	HWND consoleWindow = GetConsoleWindow();
//	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
//	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
//	SetWindowLong(consoleWindow, GWL_STYLE, style);
//}
int main()
{
	//FixConsoleWindow();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Oh wow!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				if (event.text.unicode < 128) {
					std::cout << event.text.unicode << std::endl;
				}
			}
		}

		window.clear();
		
		window.draw(shape);
		window.display();
	}

	return 0;
}