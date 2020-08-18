#pragma once
#include "Enemy.h"
#include <vector>


class Spawner 
{
public:
    Spawner();

    void drawEnemies(sf::RenderTarget& target);

    void renderEntity(sf::RenderTarget& renderer, int type, const sf::Vector2f& position);

    void initAddObject();

    void updateStepDelay();
private:

    std::vector<Object> obj;
    sf::RectangleShape m_entity;
    bool m_hasAllInvadersBeenAdded = false;
    int m_aliveInvaders = 0;

    sf::Time m_stepGap;

    int m_initX = 0;
    int m_initY = 4;
    int m_ticks = 0;
};
