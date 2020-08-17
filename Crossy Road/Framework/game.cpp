#include<iostream>
#include "game.h"
#include "../Game/State/state_playing.h"
state_base& game::cur_state() const
{
	return *_states.top();
}
game::game()
	: _window(sf::VideoMode(1280, 720), "Crossy Road", sf::Style::Close)
{
	_window.setFramerateLimit(60);
	//set icon for window, skip if failed
	sf::Image icon;
	if (icon.loadFromFile("Assets/icon.png"))
		_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//push_first_state_here
	pushState(std::make_unique<state_playing>(*this));
}

void game::run()
{
	//main game loop
	while (_window.isOpen() && _states.empty() == 0) {
		auto& state = cur_state();
		auto time = update_dt_clock();
		//Frame update
		state.update(time);
		std::cout << 1.f / time.asSeconds() << std::endl;
		//Handle event
		sf::Event event;
		while (_window.pollEvent(event)) {
			state.handleEvent(event);
			switch (event.type)
			{
			case sf::Event::Closed:
				//maybe need prompt will lose data before exit
				_window.close();
				break;
			default:
				break;
			}
		}

		//Render
		//1st buffer
		_window.clear();
		state.draw(_window);
		//2nd buffer
		_window.display();

	}
}

void game::pushState(std::unique_ptr<state_base> state)
{
	_states.push(std::move(state));
}

sf::Time game::update_dt_clock()
{
	return dt_clock.restart();
}
