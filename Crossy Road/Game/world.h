#ifndef _World_h
#define _World_h
#include"../PCH.h"
#include"Entity/Player.h"
#include"Entity/Road.h"
#include "SaveLevel.h"

using CollisionResult = std::pair<int, std::vector<sf::Vector2f>>;

enum class worldState {
	update_score,
	update_level,
	no_update
};
class World {
private:
	Player					m_player;
	std::vector<Lane>		m_lanes;
	TileMap					m_background;
	const textureLookup&	m_vehicle_set;
	random					m_rand;//random engine
public:
	World(const textureLookup&);
	/*void levelUp();*/
	void initLane(const SaveInf&);
	void resetWorld(const SaveInf&);
	void draw(sf::RenderTarget& target);
	void input();
	//worldState update(unsigned& level, unsigned& score, float dt);
	void update(float dt);
	CollisionResult tryPlayerCollideWith();
	worldState update(unsigned& level, unsigned& score, float dt);
	//unsigned getLevel();
	unsigned updateScore();
	unsigned updateLevel();
	
};
#endif // !_World_h
