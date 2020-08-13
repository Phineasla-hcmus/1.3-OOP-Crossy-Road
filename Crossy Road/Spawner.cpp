#include "Spawner.h"

 

Spawner::Spawner()
{
  
 

}

  

void Spawner::drawInvaders(sf::RenderTarget& target)
    {
        for (auto& Enemy : m_enemies) {
            if (!Enemy.isAlive()) continue;
            m_invaderRenderer.renderEntity(target, (int)invader.getType(), invader.getPosition());
        }
    }

    CollisionResult InvaderManager::tryCollideWithProjectiles(std::vector<Projectile>& projectiles)
    {
        CollisionResult result;
        std::vector<sf::Vector2f> collisionPoints;
        for (auto& projectile : projectiles) {
            for (auto& invader : m_invaders) {
                if (!invader.isAlive() || !projectile.isActive())
                    continue;
                if (projectile.tryCollideWith(invader)) {
                    m_aliveInvaders--;
                    m_invaderKilledSound.play();
                    if (m_aliveInvaders == 0) {
                        m_hasAllInvadersBeenAdded = false;
                    }
                    result.second.emplace_back(invader.getPosition());
                    result.first += ((int)invader.getType() + 1) * 100;
                    updateStepDelay();
                }
            }
        }
        return result;
    }

    sf::Vector2f InvaderManager::getRandomLowestInvaderPoint(Random<>& random)
    {
        if (m_aliveInvaders == 0) return { -1, -1 };
        //Keep looping until an invader is found
        while (true) {
            auto invaderColumn = random.getIntInRange(0, 10);
            for (int y = 4; y >= 0; y--) {
                int index = y * 11 + invaderColumn;
                auto& invader = m_invaders.at(index);
                if (invader.isAlive()) {
                    return {
                        //transform to below the invader's center
                        invader.getPosition().x + Invader::WIDTH / 2,
                        invader.getPosition().y + Invader::HEIGHT + 5
                    };
                }
            }
        }
    }

    int InvaderManager::getAliveInvadersCount() const
    {
        return m_aliveInvaders;
    }

    //Adds invaders to scene 1 at a time
    void InvaderManager::initAddInvader()
    {
        static sf::Clock delay;
        if (delay.getElapsedTime().asSeconds() > 0.02) {
            m_invaders.at(m_initY * 11 + m_initX).makeAlive();
            m_aliveInvaders++;
            m_initX++;
            if (m_initX == 11) {
                m_initX = 0;
                m_initY--;
            }
            delay.restart();
        }

        if (m_aliveInvaders == MAX_INVADERS) {
            m_hasAllInvadersBeenAdded = true;
            m_initX = 0;
            m_initY = 4;
            updateStepDelay();
        }
    }

    bool InvaderManager::areInvadersAlive() const
    {
        return m_hasAllInvadersBeenAdded;
    }

    void InvaderManager::updateStepDelay()
    {
        m_stepGap = sf::seconds((float)m_aliveInvaders / 90.0f);
    }

    bool InvaderManager::testInvaderPosition(const Invader& invader) const
    {
        if (invader.getPosition().y > Display::HEIGHT - 150) {
            m_world.setGameIsOver();
        }
        return
            (invader.getPosition().x < 15 && m_isMovingLeft) || //Check invader left
            (invader.getPosition().x + Invader::WIDTH > Display::WIDTH - 15 && !m_isMovingLeft); //Check invader right
    }
}