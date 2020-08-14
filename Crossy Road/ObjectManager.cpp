#include "ObjectManager.h"


#include <iostream>




    namespace
    {
        const int MAX_INVADERS = 55;
    }

 

    void InvaderManager::tryStepInvaders()
    {
   

    }

    void InvaderManager::drawInvaders(sf::RenderTarget& target)
    {
        for (auto& invader : m_invaders) {
            if (!invader.isAlive()) continue;
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

        if (m_aliveInvaders == 55) {
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

