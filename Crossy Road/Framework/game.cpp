#include "game.h"
game::game()
	: _window(sf::VideoMode(1280, 720), "Crossy Road")
{
	_window.setFramerateLimit(60);
	//set icon for window, nothing happen if failed
	sf::Image icon;
	if (icon.loadFromFile("resource/icon.png"))
		_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void game::run()
{
}
