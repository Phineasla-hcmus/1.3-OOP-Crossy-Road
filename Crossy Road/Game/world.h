#ifndef _World_h
#define _World_h
#include"../PCH.h"
#include"Entity/Player.h"
#include"Entity/Road.h"
#include "SaveLevel.h"


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
	bool					m_game_over=false;
public:
	World(const textureLookup&);
	void initLane(const SaveInf&);
	void resetWorld(const SaveInf&);
	void draw(sf::RenderTarget& target);
	void input();
	void update(float dt);
	bool tryPlayerCollideWith();
	unsigned updateScore();
	unsigned updateLevel();
	bool is_game_over();
	void pause();
	
};
#endif // !_World_h
