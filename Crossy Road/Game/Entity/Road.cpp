#include "Road.h"
#include "../../Framework/Util/random.h"
#include <iostream>


DRoad::DRoad(int num_Vehicle,int rand_startPos,int rand_typeVehicle,sf::Vector2f pos, float speed, int isFromLeft, Player& player) :m_player(player)
{
	this->num_Vehicle = num_Vehicle;
	this->isFromLeft = isFromLeft;
	this->m_pos = pos;
	this->m_speed = speed;
	if (isFromLeft > 0)
		this->isFromLeft = 1;
	else this->isFromLeft = -1;
	this->initVar();
	this->initShape(pos);
	this->initVehicle(rand_typeVehicle,rand_startPos);
}
	void DRoad::initVar(float width, float distance)
	{
		this->width = width;
		this->distance = distance;	
	
	}
	void DRoad::initVehicle(int k, int rand_startPos)
	{	
		
		sf::Vector2f origin_pos(rand_startPos, this->getCenterRoadPosition().y);
		for (int i = 0; i<=num_Vehicle+3; ++i) {
			r_vehicle.push_back(initVehicle_rand(k,origin_pos));
			origin_pos.x += (1280/num_Vehicle);
		}
	}
	void DRoad::initShape(sf::Vector2f position)
	{
		lane.setPosition(position);
		lane.setSize(sf::Vector2f(1260.f, width));
		lane.setFillColor(sf::Color::Cyan);
		lane.setOutlineColor(sf::Color::White);
		lane.setOutlineThickness(1.f);
	}

	float DRoad::getDistance()
	{
		return width + distance;
	}	
	sf::Vector2f DRoad::getCenterRoadPosition()
	{
		return sf::Vector2f(0, (lane.getSize().y + 2 * lane.getPosition().y) / 2);
	}

	void DRoad::draw(sf::RenderTarget& target)
	{
		target.draw(this->lane);
		for (auto& e : this->r_vehicle) {
			e->draw(target);
		}

	}
	void DRoad::spawnVehicle()
	{
		
		Vehicle* v;
		if (this->isFromLeft == 1) {
			if (typeid(*this->r_vehicle[0])==typeid(Car)) {
				v = new Car(getCenterRoadPosition());
			}
			else if (typeid(*this->r_vehicle[0]) == typeid(Truck)) {
				v = new Truck(this->getCenterRoadPosition());
			}
			else v= new Bird(this->getCenterRoadPosition());
			r_vehicle.push_back(v);
		}
		else {
			if (typeid(*this->r_vehicle[0]) == typeid(Car)){
				v = new Car({1280-90,getCenterRoadPosition().y });
			}
			else if (typeid(*this->r_vehicle[0]) == typeid(Truck)){ 
				v = new Truck({1280-90,this->getCenterRoadPosition().y}); 
			}
			else v = new Bird({1280-90,this->getCenterRoadPosition().y});
			r_vehicle.push_back(v);
		}
	}
	
	void DRoad::update(float dt,int level)
	{
		//Updating the timer for enemy spawning
		if (this->r_vehicle.size() < this->num_Vehicle)
		{
			this->spawnVehicle();

		}

		//Moving and updating enemies
		for (int i = 0; i < this->r_vehicle.size(); i++)
		{

			this->r_vehicle[i]->vehicle.move(double(this->m_speed*dt * this->isFromLeft), 0.f);
			this->tryCollideWithPlayer();
			if (this->isFromLeft == 1 && this->r_vehicle[i]->vehicle.getPosition().x > 1280)
				this->r_vehicle.erase(this->r_vehicle.begin() + i);
			if (this->isFromLeft == -1 && (this->r_vehicle[i]->vehicle.getPosition().x+this->r_vehicle[i]->vehicle.getSize().x) < 0)
				this->r_vehicle.erase(this->r_vehicle.begin() + i);
			
		}
	}

	
	CollisionResult DRoad::tryCollideWithPlayer() {
		CollisionResult result;
		for (int i = 0; i < r_vehicle.size(); ++i) {
			if (!m_player.isAlive())
				continue;

			if (m_player.tryCollideWith(*(r_vehicle[i]))) {
				std::cout << "Collided!!" << std::endl;
			}
		}
		return result;
	}
