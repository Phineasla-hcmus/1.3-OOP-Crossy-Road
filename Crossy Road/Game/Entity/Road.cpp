#include "Road.h"
#include <iostream>


DRoad::DRoad(sf::Vector2f pos, float speed, int isFromLeft, Player& player) :m_player(player)
{
	this->isFromLeft = isFromLeft;
	this->m_pos = pos;
	this->m_speed = speed;
	if (isFromLeft > 0)
		this->isFromLeft = 1;
	else this->isFromLeft = -1;
	this->initVar();
	this->initShape(pos);
	this->initVehicle();
}
	void DRoad::initVar(float width, float distance)
	{
		this->width = width;
		this->distance = distance;	
		maxVehicle = 5;
	}
	void DRoad::initVehicle()
	{
		Vehicle* v;		
		
		int rand_num = rand() % 3;
		auto rand_distance = rand() % 100-50;
		if (rand_num==1) {
			v = new Car({ 0.f + rand_distance,getCenterRoadPosition().y });
		}
		else if(rand_num==2)
		v = new Bike({0.f+ rand_distance,this->getCenterRoadPosition().y });
		else v=new Bird({ 0.f + rand_distance,this->getCenterRoadPosition().y });
		r_vehicle.push_back(v);
		

		if (rand_num == 1) {
			v = new Car({ 256.f + rand_distance,getCenterRoadPosition().y });
		}
		else if (rand_num == 2)
			v = new Bike({ 256.f + rand_distance,this->getCenterRoadPosition().y });
		else v = new Bird({ 256.f + rand_distance,this->getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand_num == 1) {
			v = new Car({ 512.f + rand_distance,getCenterRoadPosition().y });
		}
		else if (rand_num == 2)
			v = new Bike({ 512.f + rand_distance,this->getCenterRoadPosition().y });
		else v = new Bird({ 512.f + rand_distance,this->getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand_num == 1) {
			v = new Car({ 768.f + rand_distance,getCenterRoadPosition().y });
		}
		else if (rand_num == 2)
			v = new Bike({ 768.f + rand_distance,this->getCenterRoadPosition().y });
		else v = new Bird({ 768.f + rand_distance,this->getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand_num == 1) {
			v = new Car({ 1024.f + rand_distance,getCenterRoadPosition().y });
		}
		else if (rand_num == 2)
			v = new Bike({ 1024.f + rand_distance,this->getCenterRoadPosition().y });
		else v = new Bird({ 1024.f + rand_distance,this->getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand_num == 1) {
			v = new Car({ 1280.f + rand_distance,getCenterRoadPosition().y });
		}
		else if (rand_num == 2)
			v = new Bike({ 1280.f + rand_distance,this->getCenterRoadPosition().y });
		else v = new Bird({ 1280.f + rand_distance,this->getCenterRoadPosition().y });
		r_vehicle.push_back(v);

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
			else if(typeid(*this->r_vehicle[0]) == typeid(Bike))
				v = new Bike(this->getCenterRoadPosition());
			else v= new Bird(this->getCenterRoadPosition());
			r_vehicle.push_back(v);
		}
		else {
			if (typeid(*this->r_vehicle[0]) == typeid(Car)) {
				v = new Car({ 1280,getCenterRoadPosition().y });
			}
			else if(typeid(*this->r_vehicle[0]) == typeid(Bike))
				v = new Bike({ 1280,this->getCenterRoadPosition().y });
			else v = new Bird({ 1280,this->getCenterRoadPosition().y });
			r_vehicle.push_back(v);
		}
	}
	
	void DRoad::update(float dt,int level)
	{
		//Updating the timer for enemy spawning
		if (this->r_vehicle.size() < this->maxVehicle)
		{
			this->spawnVehicle();

		}

		//Moving and updating enemies
		for (int i = 0; i < this->r_vehicle.size(); i++)
		{

			this->r_vehicle[i]->vehicle.move(double(this->m_speed*dt*level * this->isFromLeft), 0.f);
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
