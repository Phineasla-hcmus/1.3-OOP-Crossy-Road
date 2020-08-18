#include "Spawner.h"

 

Spawner::Spawner()
{
  
 

}

  void Spawner::drawEnemies(sf::RenderTarget& target)
    {
        for (auto& Object : obj) {
            if (!Object.isAlive()) continue;
            renderEntity(target, (int)Object.getType(), Object.getPosition());
        }
    }




    //Adds invaders to scene 1 at a time
  void Spawner::initAddObject()
  {
      static sf::Clock delay;
      if (delay.getElapsedTime().asSeconds() > 0.02) {
          obj.at(m_initY * 11 + m_initX).makeAlive();
          m_aliveInvaders++;
          m_initX++;
          if (m_initX == 11) {
              m_initX = 0;
              m_initY--;
          }
          delay.restart();
      }

      if (m_aliveInvaders == 1) {
          m_hasAllInvadersBeenAdded = true;
          m_initX = 0;
          m_initY = 4;
          updateStepDelay();
      }
  }

  void Spawner::updateStepDelay()
  {
      m_stepGap = sf::seconds((float)m_aliveInvaders / 90.0f);
  }
void Spawner::renderEntity(sf::RenderTarget& renderer, int type, const sf::Vector2f& position)
{
    //Reposition and draw sprite
    m_entity.setPosition(position);

    renderer.draw(m_entity);
}