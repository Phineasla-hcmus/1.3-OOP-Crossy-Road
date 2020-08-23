#include "state_playing.h"
#include<iostream>


state_playing::state_playing(Game& game)
	: StateBase(game)
	, _world(),pause_menu(game)
{
    
}

void state_playing::handleEvent(sf::Event ev)
{
    if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
    {
        pause_menu.changeState();
        _is_paused = !_is_paused;
    }
    if (_is_paused ) pause_menu.handleEvent(ev);
    if (_is_gameover) {
       //m_gameOverMenu.handleEvent(e, m_pGame->getWindow());
    }
}

void state_playing::handleInput()
{
    _world.input();
   
}

void state_playing::draw(sf::RenderTarget& renderer)
{
    _world.draw(renderer);
    if (_is_paused) pause_menu.draw(renderer); 
    
   
  //  m_lifeDisplay.draw(renderer, m_world.getPlayer().getLives());
  //  m_scoreDisplay.draw(renderer);
   // m_highestScoreDisplay.draw(renderer);

    if (_is_gameover) {
      //  m_gameOverMenu.render(renderer);
    }

}

void state_playing::update(sf::Time delta_time)
{
    if (!_is_gameover &&!_is_paused) {
        _score += _world.update(delta_time.asSeconds());
       // m_scoreDisplay.update(m_score);

       // if (m_score > m_highestScoreDisplay.getCurrentScoreDisplayed()) {
        //    m_highestScoreDisplay.update(m_score);
       // }
    }
    _is_gameover = _world.isGameOver();
    _is_paused = pause_menu.isPaused();
  
}


