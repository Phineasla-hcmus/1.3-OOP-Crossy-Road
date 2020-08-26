#include "World.h"
int World::level = 1;

World::World()
{
	random rand;
	std::array<int, 4> vehicle_type;
	for (auto& it : vehicle_type) {
		it = rand.int_in_range(0, 2);
	}
	//init road
	resetRoad();
}

void World::input()
{
	if (m_player.isAlive()) {
		m_player.keymove();

	}
}

int World::update(float dt)
{
	int score = 0;
	for (auto& road : this->m_road)
		road.update(dt,this->level);
	m_player.moving();
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

void World::resetRoad()
{
  //  ++level;

	m_road.clear();
	random rand;
	float y_startPos = 0;
	int isFromLeft = 1;
	float speed = base_vehicle_speed + World::level * step_vehicle_speed;
	auto m_level = World::level;
	
	int numVehicle = ((m_level <= 3) ? 2 : (m_level <= 5 ? 3 : 4));
	for (int i = 0; i < 4; ++i) {
		sf::Vector2f origin_Pos;
		origin_Pos.x = 10;
		origin_Pos.y = y_startPos;
		m_road.push_back({ numVehicle+rand.int_in_range(-1,1),rand.int_in_range(-150,150),rand.int_in_range(0, 2),origin_Pos,speed+rand.int_in_range(-10,10),isFromLeft ,m_player });
		y_startPos = origin_Pos.y + m_road[0].getDistance();
		isFromLeft = isFromLeft * -1;
	}
}

int World::getLevel() const
{
	return level;
}

void World::levelUp()
{
	++level;
}

void World::draw(sf::RenderTarget& target)
{

	for (auto& droad : m_road) {
		droad.draw(target);
	}
	m_player.draw(target);

}