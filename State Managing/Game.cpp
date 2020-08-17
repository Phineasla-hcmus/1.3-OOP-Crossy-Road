#include "Game.h"

#include "StateBase.h"
StateBase& Game::cur_state() const
{
	return *m_states.top();
}
Game::Game()
	: window(sf::VideoMode(1280, 720), "Crossy Road")
{
	window.setFramerateLimit(60);
	pushState<StateMainMenu>(*this);
	//set icon for window, nothing happen if failed
	/*sf::Image icon;
	if (icon.loadFromFile("resource/icon.png"))
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());*/
	//push_first_state_here
}

void Game::run()
{
	//main game loop
	while (window.isOpen() && m_states.empty() == 0) {
		auto& state = cur_state();
		//Frame update
		state.update(update_dt_clock());
		//Handle event
		sf::Event event;
		while (window.pollEvent(event)) {
			state.handleEvent(event);
			switch (event.type)
			{
			case sf::Event::Closed:
				//maybe need prompt will lose data before exit
				window.close();
				break;
			default:
				break;
			}
		}
		if (exit == true) {
			return;
		}

		//Render
		//1st buffer
		window.clear();
		state.render(window);
		//2nd buffer
		window.display();

	}
}

void Game::pushState(std::unique_ptr<StateBase> state)
{
	m_states.push(std::move(state));
}

sf::Time Game::update_dt_clock()
{
	return dt_clock.restart();
}
const sf::RenderWindow& Game::getWindow() const
{
	return window;
}