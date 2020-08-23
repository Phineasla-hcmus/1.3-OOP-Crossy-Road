#include "World.h"
#include <time.h>
#include "../Framework/Util/random.h"

int World::level = 1;

World::World()
{
    random rand;
  
    //init road
    float y_startPos = 0;
    int isFromLeft = 1;
    float speed = 50 + World::level * 10;
    int numVehicle = (World::level > 5) ? 5 : 4;
    for (int i = 0; i < 4; ++i) {
        sf::Vector2f origin_Pos;
        origin_Pos.x = 10;
        origin_Pos.y = y_startPos;
        m_road.push_back({ numVehicle,rand.int_in_range(-150,150),rand.int_in_range(0,2),origin_Pos,speed,isFromLeft ,_people});
        y_startPos = origin_Pos.y + m_road[0].getDistance();
        isFromLeft = isFromLeft * -1;
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
        road.update(dt,this->level);

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