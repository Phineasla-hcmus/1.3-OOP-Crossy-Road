#include "World.h"

World::World(const texture_set& set, const SaveInf& save)
	: m_vehicle_set(set)
	, m_background(&asset::texture().get("tileset", "png"), sf::Vector2u(16, 16))//size base on the tileset.png
{
	for (size_t i = 0; i < save_lane; ++i) {

	}
}
