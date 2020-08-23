#include "state_playing.h"
#include <iostream>

state_playing::state_playing(Game& game)
	: state_base(game)
	, m_world()
{

}

void state_playing::handleEvent(sf::Event ev)
{
    if (m_is_gameover) {
        //m_gameOverMenu.handleEvent(e, m_pGame->getWindow());
    }
}

void state_playing::handleInput()
{
    m_world.input();
}

void state_playing::draw(sf::RenderTarget& renderer)
{
    m_world.draw(renderer);

  //  m_lifeDisplay.draw(renderer, m_world.getPlayer().getLives());
  //  m_scoreDisplay.draw(renderer);
   // m_highestScoreDisplay.draw(renderer);

    if (m_is_gameover) {
      //  m_gameOverMenu.render(renderer);
    }

}

void state_playing::update(sf::Time delta_time)
{
    if (!m_is_gameover) {
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
    

    m_is_gameover = m_world.isGameOver();
}


