#include "state_playing.h"
#include <iostream>

state_playing::state_playing(Game& game)
	: state_base(game)
	, m_world(),pause_menu(game)
{

}

void state_playing::handleEvent(sf::Event ev)
{
    if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
    {
        pause_menu.changeState();
        _is_paused = !_is_paused;
    }
    if (_is_paused) pause_menu.handleEvent(ev);
    if (m_is_gameover) {
        //m_gameOverMenu.handleEvent(e, m_pGame->getWindow());
    }
}

void state_playing::handleInput()
{
     if(!_is_paused)m_world.input();
}

void state_playing::draw(sf::RenderTarget& renderer)
{
    m_world.draw(renderer);
    if (_is_paused) pause_menu.draw(renderer);
  //  m_lifeDisplay.draw(renderer, m_world.getPlayer().getLives());
  //  m_scoreDisplay.draw(renderer);
   // m_highestScoreDisplay.draw(renderer);

    if (m_is_gameover) {
      //  m_gameOverMenu.render(renderer);
    }

}

void state_playing::update(sf::Time delta_time)
{
    if (!m_is_gameover && !_is_paused) {
        m_score += m_world.update(delta_time.asSeconds());
       // m_scoreDisplay.update(m_score);

       // if (m_score > m_highestScoreDisplay.getCurrentScoreDisplayed()) {
        //    m_highestScoreDisplay.update(m_score);
       // }
    }
    if (m_level != m_world.getLevel()) {
        m_world.resetRoad();
        m_level = m_world.getLevel();
        std::cout << m_world.getLevel() << "\n";
    }
    
    _is_paused = pause_menu.isPaused();
    m_is_gameover = m_world.isGameOver();
}


