#include "Road.h"


Lane::Lane(const sf::Vector2f road_pos = { 0.f,0.f }, const direction dir=left, float speed=30.f)
	: m_pos(road_pos)
	, m_dir(dir)
	, m_speed(speed)
	, m_vehicles_texture(nullptr)
	//, m_light({ road_pos.x,road_pos.y + 90 })
{}

void Lane::initVehicle(size_t size, random& rand)
{
	if (m_init_func) {
		float spacing = SCREEN_WIDTH / (float)size;
		//origin x with some offset for randomness
		float x = LEFT_BOUND;// +(float)rand.double_in_range(-spacing, spacing);
		size += HIDDEN_VEHICLE;//increase size with extra vehicle

		m_vehicles.reserve(size);
		for (size_t i = 0; i < size; ++i) {
			x += spacing;
			//create vehicle at x, lanePos.y
			auto new_vehicle = m_init_func(sf::Vector2f(x, m_pos.y), *m_vehicles_texture, m_texture_bound);
			float scale = VEHICLE_SIZE / m_texture_bound.height;
			new_vehicle->setScale(sf::Vector2f(scale, scale));

			m_vehicles.push_back(std::move(new_vehicle));
		}
	}
}

void Lane::setVehicleType(vehicle_func funct, sf::Texture& vehicle, sf::IntRect texture_bound)
{
	m_init_func			= funct;
	m_vehicles_texture	= &vehicle;
	m_texture_bound		= texture_bound;
}

size_t Lane::getVehicleSize() const
{
	return m_vehicles.size();
}

Vehicle& Lane::getVehicle(size_t idx)
{
	return *m_vehicles[idx];
}

void Lane::draw(sf::RenderTarget& target)
{
	//target.draw(this->lane);
	//m_light.draw(target);
	
	for (auto& e : this->m_vehicles) {
		e->draw(target);
	}
	
}

void Lane::update(unsigned& level, float dt)
{
	float speed = m_speed * level * (int)m_dir * dt;
	for (auto& vehicle : this->m_vehicles)
		vehicle->move(speed);

	//if (m_light.getLightState() == (sf::Color::Green)) {
	//	if (m_time.getElapsedTime() <= (m_start_Point + m_green_time)) {
	//		for (int i = 0; i < this->m_vehicles.size(); i++)
	//		{

	//			this->m_vehicles[i]->move(speed);
	//			//this->tryCollideWithPlayer();
	//			if (this->m_dir == left && this->m_vehicles[i]->getPosition().x > 1280)
	//				this->m_vehicles.erase(this->m_vehicles.begin() + i);
	//			if (this->m_dir == right && (this->m_vehicles[i]->getPosition().x + this->m_vehicles[i]->getSize().x) < 0)
	//				this->m_vehicles.erase(this->m_vehicles.begin() + i);

	//		}
	//	}
	//	else {
	//		m_light.turnRed();
	//		m_red_time = sf::seconds(0.5f + (rand() % 10 * 1.0 / 10));
	//		m_start_Point = m_time.getElapsedTime();
	//	}
	//}
	//else {

	//	if (m_time.getElapsedTime() >= (m_start_Point + m_red_time)) {
	//		m_light.turnGreen();
	//		m_start_Point = m_time.getElapsedTime();
	//		m_green_time = sf::seconds(5.f + (rand() % 40 * 1.0 / 20));
	//	}
	//}
}


