#include "Road.h"
//#include "Lane.h"
//#include "../../Framework/Util/random.h"
//#include <iostream>
//
//
//DRoad::DRoad(int num_Vehicle,int rand_startPos,int rand_typeVehicle,sf::Vector2f pos, float speed, int isFromLeft, Player& player) :m_player(player)
//{
//	this->num_Vehicle = num_Vehicle;
//	this->isFromLeft = isFromLeft;
//	this->m_pos = pos;
//	this->speed = speed;
//	if (isFromLeft > 0)
//		this->isFromLeft = 1;
//	else this->isFromLeft = -1;
//	this->initVar();
//	this->initShape(pos);
//	this->initVehicle(rand_typeVehicle,rand_startPos);
//}
//	void DRoad::initVar(float width, float distance)
//	{
//		this->width = width;
//		this->distance = distance;	
//	
//	}
//	void DRoad::initVehicle(int k, int rand_startPos)
//	{	
//		
//		sf::Vector2f origin_pos(rand_startPos, this->getCenterRoadPosition().y);
//		for (int i = 0; i<=num_Vehicle+3; ++i) {
//			r_vehicle.push_back(initVehicle_rand(k,origin_pos));
//			origin_pos.x += (1280/num_Vehicle);
//		}
//	}
//	void DRoad::initShape(sf::Vector2f position)
//	{
//		lane.setPosition(position);
//		lane.setSize(sf::Vector2f(1260.f, width));
//		lane.setFillColor(sf::Color::Cyan);
//		lane.setOutlineColor(sf::Color::White);
//		lane.setOutlineThickness(1.f);
//	}
//
//	float DRoad::getDistance()
//	{
//		return width + distance;
//	}	
//	sf::Vector2f DRoad::getCenterRoadPosition()
//	{
//		return sf::Vector2f(0, (lane.getSize().y + 2 * lane.getPosition().y) / 2);
//	}
//
//	void DRoad::draw(sf::RenderTarget& target)
//	{
//		target.draw(this->lane);
//		for (auto& vehicle : this->r_vehicle) {
//			vehicle->draw(target);
//		}
//
//	}
//	void DRoad::spawnVehicle()
//	{
//		
//		Vehicle* v;
//		if (this->isFromLeft == 1) {
//			if (typeid(*this->r_vehicle[0])==typeid(Car)) {
//				v = new Car(getCenterRoadPosition());
//			}
//			else if (typeid(*this->r_vehicle[0]) == typeid(Truck)) {
//				v = new Truck(this->getCenterRoadPosition());
//			}
//			else v= new Bird(this->getCenterRoadPosition());
//			r_vehicle.push_back(v);
//		}
//		else {
//			if (typeid(*this->r_vehicle[0]) == typeid(Car)){
//				v = new Car({1280-90,getCenterRoadPosition().y });
//			}
//			else if (typeid(*this->r_vehicle[0]) == typeid(Truck)){ 
//				v = new Truck({1280-90,this->getCenterRoadPosition().y}); 
//			}
//			else v = new Bird({1280-90,this->getCenterRoadPosition().y});
//			r_vehicle.push_back(v);
//		}
//	}
//	
//	void DRoad::update(float dt,int level)
//	{
//		//Updating the timer for enemy spawning
//		if (this->r_vehicle.size() < this->num_Vehicle)
//		{
//			this->spawnVehicle();
//
//		}
//
//		//Moving and updating enemies
//		for (int i = 0; i < this->r_vehicle.size(); i++)
//		{
//
//			this->r_vehicle[i]->vehicle.move(double(this->speed*dt*level * this->isFromLeft), 0.f);
//			this->tryCollideWithPlayer();
//			if (this->isFromLeft == 1 && this->r_vehicle[i]->vehicle.getPosition().x > 1280)
//				this->r_vehicle.erase(this->r_vehicle.begin() + i);
//			if (this->isFromLeft == -1 && (this->r_vehicle[i]->vehicle.getPosition().x+this->r_vehicle[i]->vehicle.getSize().x) < 0)
//				this->r_vehicle.erase(this->r_vehicle.begin() + i);
//			
//		}
//	}
//
//	
//	CollisionResult DRoad::tryCollideWithPlayer() {
//		CollisionResult result;
//		for (int i = 0; i < r_vehicle.size(); ++i) {
//			if (!m_player.isAlive())
//				continue;
//
//			if (m_player.tryCollideWith(*(r_vehicle[i]))) {
//				std::cout << "Collided!!" << std::endl;
//			}
//		}
//		return result;
//	}

Lane::Lane(const sf::Vector2f road_pos = { 0.f,0.f }, const direction dir=left, float speed=30.f)
	: m_pos(road_pos)
	, m_dir(dir)
	, m_speed(speed)
	, m_vehicles_texture(nullptr)
{}

void Lane::initVehicle(size_t size, random& rand)
{
	if (m_init_func) {
		float spacing = SCREEN_WIDTH / (float)size;
		//origin x with some offset for randomness
		float x = LEFT_BOUND + (float)rand.double_in_range(-spacing, spacing);
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
	//light.draw(target);
	
	for (auto& e : this->m_vehicles) {
		e->draw(target);
	}
	
}

void Lane::update(unsigned& level, float dt)
{
	float speed = m_speed * level * (int)m_dir * dt;
	for (auto& vehicle : this->m_vehicles)
		vehicle->move(speed);
}


