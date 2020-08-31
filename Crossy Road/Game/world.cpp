#include "World.h"

World::World(const textureLookup& lookup)
	: m_vehicle_set(lookup)
	, m_background(&asset::texture().get("road_textures", "png"), sf::Vector2u(20, 20))//size base on the tileset.png
	, m_rand()
{

	//render background map(top to bottom)
	const std::vector<unsigned> tile_map = { 1,0,1,0,1,0,1,0 };
	//render y_tiles+1 to fill whole screen
	m_background.setMapSize(x_tiles+1, y_tiles);
	//scale the texture to tile_size (90)
	m_background.create_map(tile_map, sf::Vector2u(tile_size, tile_size));
}

void World::initLane(const SaveInf& save)
{
	//function for init
	m_lanes.reserve(SAVE_LANE);
	vehicle_func initVehicleFunc[] = { new_vehicle<Truck> , new_vehicle<Car>};
	for (size_t i = 0; i < SAVE_LANE; ++i) {
		const float			lanePos = i * tile_size * 2.f;					
		const auto&			laneInf = save.get_RoadInf(i);							//get each laneInf from save file
		m_lanes.emplace_back(Lane(sf::Vector2f(0, lanePos), (Lane::direction)laneInf.direction, laneInf.speed));
		Lane&				newLane = m_lanes.back();
		/*use for set vInfo type and its texture*/
		const textureSet&	set		= m_vehicle_set.getSet(laneInf.vehicleType);	//get a set of multiple texture of a vInfo type
		unsigned			idx		= m_rand.int_in_range(0, set.size() - 1);		//random to choose a texture for vehicle in that road
		const textureInf&	vInfo	= set.getFullInf(idx);							//get all info about texture
		sf::Texture&		texture	= asset::texture().get(vInfo.name, vInfo.ext);
		const sf::IntRect	bounds	= (laneInf.direction == Lane::direction::left) 
			? vInfo.getBounds(0) 
			: vInfo.getBounds(1);
		/*set function for init, texture and texture bounds*/
		newLane.setVehicleType(initVehicleFunc[laneInf.vehicleType], texture, bounds);
		newLane.initVehicle(laneInf.vehicleNum, m_rand);
	}
}
void World::input()
{
	if (m_player.isAlive()) {
		m_player.keymove();
	}
}

worldState World::update(unsigned& level, unsigned& score, float dt)
{
	//check for level up
	if (m_player.getPosition().y <= SCREEN_HEIGHT && m_player.getPosition().y > SCREEN_HEIGHT - 5) {
		++level;
		return worldState::update_level;
	}

	this->tryPlayerCollideWith();
	for (auto& lane : this->m_lanes)
		lane.update(dt);
	return worldState::no_update;
}
void World::resetWorld(const SaveInf& new_save)
{
	m_lanes.clear();
	initLane(new_save);
	//m_player.restart();
}

void World::draw(sf::RenderTarget& target)
{
	
	target.draw(m_background);
	for (auto& lane : m_lanes) {
		lane.draw(target);
	}
	m_player.moving();
	m_player.animationRenderer();
	m_player.draw(target);
}
CollisionResult World::tryPlayerCollideWith() {
	CollisionResult result;
	for (int i = 0; i < m_lanes.size(); i++) {
		if (!m_player.isAlive())
			continue;
		if (m_player.tryCollideWith(m_lanes[i].getVehicle(3))
			|| m_player.tryCollideWith(m_lanes[i].getVehicle(2))
			|| m_player.tryCollideWith(m_lanes[i].getVehicle(1))
			||	m_player.tryCollideWith(m_lanes[i].getVehicle(0))) {
			std::cout << "Collided\n";
		}
	}
	return result;
}
