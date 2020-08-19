#include "World.h"
#include <time.h>


World::World()
{

    //init road
    float old = 0;
    int k = 1;
    for (int i = 0; i < 4; ++i) {
        sf::Vector2f pos;
        pos.x = 0;
        pos.y = old;
        m_road.push_back({ pos,4.f,k });
        old = pos.y + m_road[0].getDistance();
        k = k * -1;
    }
}

void World::input()
{
    if (m_player.isAlive()) {
        m_player.inputKeyPress();

    }
}

int World::update(float dt)
{
    int score = 0;
    for (auto& road : this->m_road)
        road.update(dt);

    m_player.update(dt);
    return score;
}

const Player& World::getPlayer() const
{
    return m_player;
}

bool World::isGameOver() const
{
    return _isGameOver;
}




void World::draw(sf::RenderTarget& target)
{

    for (auto& droad : m_road) {
        droad.draw(target);
    }
    m_player.draw(target);


}