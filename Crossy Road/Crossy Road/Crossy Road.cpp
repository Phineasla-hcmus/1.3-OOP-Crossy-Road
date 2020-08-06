#include <SFML/Graphics.hpp>
#include<Windows.h>
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
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		window.draw(shape);
		window.display();
	}

	return 0;
}