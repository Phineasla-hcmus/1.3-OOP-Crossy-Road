#include<iostream>
#include "game.h"
#include "../Game/State/state_playing.h"
state_base& Game::cur_state() const
{
	return *m_states.top();
}
Game::Game()
	//set resolution, window's title and disable fullscreen
	: m_window(sf::VideoMode(screen_width, screen_height), "Crossy Road", sf::Style::Close)
{
	m_window.setFramerateLimit(60);
	sf::Image icon;
	//set icon for window, skip if failed
	if (icon.loadFromFile("Assets/icon.png"))
		m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	//push first state here
	pushState(std::make_unique<state_playing>(*this));
}

void Game::run()
{
	m_window.setKeyRepeatEnabled(false);
	//main game loop
	while (m_window.isOpen() && m_states.empty() == 0) {
		auto& state = cur_state();
		auto time = update_dt_clock();
		//Frame update
		//std::cout << 1.f / time.asSeconds() << std::endl;
		//state.handleInput();
		state.update(time);
		//Handle event
		sf::Event event;
		while (m_window.pollEvent(event)) {
			state.handleEvent(event);
			state.handleInput();
			switch (event.type)
			{
			case sf::Event::Closed:
				//maybe need prompt "will lose data" before exit
				m_window.close();
				break;
			default:
				break;
			}
		}

		//Render
		m_window.clear();
		//1st buffer
		state.draw(m_window);
		//2nd buffer
		m_window.display();
	}
	m_window.close();
}

void Game::pushState(std::unique_ptr<state_base> state)
{
	m_states.push(std::move(state));
}

void Game::popState()
{

}

const sf::RenderWindow& Game::get_window() const
{
	return m_window;
}

sf::Time Game::update_dt_clock()
{
	return dt_clock.restart();
}
