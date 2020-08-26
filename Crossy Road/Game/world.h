#ifndef _World_h
#define _World_h
#include"../PCH.h"
#include"Entity/Player.h"
#include"Entity/Road.h"
class World {
private:
	Player				m_player;
	std::vector<Lane>	m_lanes;
	TileMap				m_background;
};
#endif // !_World_h
