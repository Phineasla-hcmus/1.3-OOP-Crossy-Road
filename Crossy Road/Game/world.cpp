#include "World.h"
#include <time.h>


World::World()
{

    //init road
    float y_startPos = 0;
    int k = 1;
    for (int i = 0; i < 4; ++i) {
        sf::Vector2f pos;
        pos.x = 10;
        pos.y = y_startPos;
        m_road.push_back({ pos,4.f,k });
        y_startPos = pos.y + m_road[0].getDistance();
        k = k * -1;
    }
}

void World::input()
{
    if (_people.isAlive()) {
        _people.inputKeyPress();

    }
}

int World::update(float dt)
{
    int score = 0;
    for (auto& road : this->m_road)
        road.update(dt);

    _people.update(dt);
    return score;
}

const Player& World::getPlayer() const
{
    return _people;
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
    _people.draw(target);


}