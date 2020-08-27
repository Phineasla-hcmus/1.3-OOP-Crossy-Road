#include "World.h"

World::World(const textureLookup& lookup)
	: m_vehicle_set(lookup)
	, m_background(&asset::texture().get("tileset", "png"), sf::Vector2u(16, 16))//size base on the tileset.png
	, m_rand()
{
	//lookup background
	const std::vector<unsigned> tile_map = { 0,1,0,1,0,1,0,1 };
	//render y_tiles+1 to fill whole screen
	m_background.setMapSize(x_tiles+1, y_tiles);
	//scale the texture to tile_size (90)
	m_background.create_map(tile_map, sf::Vector2u(tile_size, tile_size));
}

void World::initLane(const SaveInf& save)
{
	vehicle_func initVehicleFunc[] = { new_vehicle<Car>,new_vehicle<Truck> };
	for (size_t i = 0; i < save_lane; ++i) {
		const auto& laneInf = save.get_road_inf(i);
		const float lanePos = i * tile_size * 2.f;
		Lane		newLane(sf::Vector2f(0, lanePos), (Lane::direction)laneInf.m_dir, laneInf.m_speed);
		//temporary texture, need to replace random one
		newLane.setVehicleType(initVehicleFunc[laneInf.m_type], asset::texture().get("car2", "png"), 80);
		m_lanes.push_back(std::move(newLane));//prevent copy because lane have unique_ptr
	}
}

void World::draw(sf::RenderTarget& target)
{
	target.draw(m_background);
	for (auto& droad : m_lanes) {
		droad.draw(target);
	}
	m_player.draw(target);
	
}
