#ifndef _World_h
#define _World_h
#include"../PCH.h"
#include"Entity/Player.h"
#include"Entity/Road.h"
#include "SaveLevel.h"
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
	void update(uint& level, uint& score,float dt);
	//unsigned getLevel();
	
};
#endif // !_World_h
