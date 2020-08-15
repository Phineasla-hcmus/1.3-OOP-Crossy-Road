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

      obj.at(m_initY * 11 + m_initX).makeAlive();
  }


void Spawner::renderEntity(sf::RenderTarget& renderer, int type, const sf::Vector2f& position)
{
    //Reposition and draw sprite
    m_entity.setPosition(position);

    renderer.draw(m_entity);
}