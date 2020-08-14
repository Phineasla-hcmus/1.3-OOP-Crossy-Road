#include "game.h"
state_base& game::cur_state() const
{
	return *_states.top();
}
game::game()
	: _window(sf::VideoMode(1280, 720), "Crossy Road")
{
	_window.setFramerateLimit(60);
	//set icon for window, nothing happen if failed
	sf::Image icon;
	if (icon.loadFromFile("resource/icon.png"))
		_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//push_first_state_here
}

void game::run()
{
	//main game loop
	while (_window.isOpen() && _states.empty() == 0) {
		auto& state = cur_state();
		//Frame update
		state.update(update_dt_clock());
	}
}

sf::Time game::update_dt_clock()
{
	return dt_clock.restart();
}
