#ifndef _World_h
#define _World_h
#include"../PCH.h"
#include"Entity/Player.h"
#include"Entity/Road.h"
#include"SaveLevel.h"
constexpr auto x_tile_size = 14;
constexpr auto y_tile_size = 8;
class World {
private:
	Player					m_player;
	std::vector<Lane>		m_lanes;
	TileMap					m_background;
	const textureLookup&	m_vehicle_set;
	random					m_rand;//random engine
public:
	World(const textureLookup&);
	void initLane(const SaveInf&);
};
#endif // !_World_h
