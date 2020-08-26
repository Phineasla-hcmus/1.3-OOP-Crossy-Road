#ifndef _World_h
#define _World_h
#include"../PCH.h"
#include"Entity/Player.h"
#include"Entity/Road.h"
#include"SaveLevel.h"
class World {
private:
	Player				m_player;
	std::vector<Lane>	m_lanes;
	TileMap				m_background;
	SaveInf				m_save;
	const texture_set&	m_vehicle_set;
public:
	World(const texture_set&, const SaveInf&);
};
#endif // !_World_h
