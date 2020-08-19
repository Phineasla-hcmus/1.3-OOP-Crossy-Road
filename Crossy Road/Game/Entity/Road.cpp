#include "Road.h"
#include <iostream>


DRoad::DRoad(sf::Vector2f pos, float speed, int isFromLeft, Player& m_player) :player(m_player)
{
	srand((unsigned)time(NULL));
<<<<<<< Updated upstream
	this->speed = speed;
	if (isFromLeft > 0)
		this->isFromLeft = 1;
	else this->isFromLeft = -1;
	this->initVar();
	this->initShape(pos);
	this->initVehicle();
=======
	speed = speed;
	if (isFromLeft > 0)
		isFromLeft = 1;
	else isFromLeft = -1;
	initVar();
	initShape(pos);
	initVehicle();
>>>>>>> Stashed changes
}
	void DRoad::initVar(float width, float distance)
	{
		this->width = width;
		this->distance = distance;
		vehicleSpawnTimerMax = 3;
		vehicleSpawnTimer = vehicleSpawnTimerMax;
		maxVehicle = 10;
	}
	void DRoad::initVehicle()
	{
		Vehicle* v;
		sf::Clock c;
		srand(unsigned(c.getElapsedTime().asMicroseconds() * 1000));
		float rand_position = rand() % 100;
		if (rand() % 2 == 0) {
			v = new Car(getCenterRoadPosition());
		}
		else v = new Bike({ rand_position,this->getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand() % 2 == 0) {
			v = new Car({ 256.f + rand_position,getCenterRoadPosition().y });
		}
		else v = new Bike({ 256.f + rand_position,getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand() % 2 == 0) {
			v = new Car({ 512.f + rand_position,getCenterRoadPosition().y });
		}
		else v = new Bike({ 512.f + rand_position,getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand() % 2 == 0) {
			v = new Car({ 768.f + rand_position,getCenterRoadPosition().y });
		}
		else v = new Bike({ 768.f + rand_position,getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand() % 2 == 0) {
			v = new Car({ 1024.f + rand_position,getCenterRoadPosition().y });
		}
		else v = new Bike({ 1024.f + rand_position,getCenterRoadPosition().y });
		r_vehicle.push_back(v);

		if (rand() % 2 == 0) {
			v = new Car({ 1280.f + rand_position,getCenterRoadPosition().y });
		}
		else v = new Bike({ 1280.f + rand_position,getCenterRoadPosition().y });
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
	void DRoad::tryCollide(sf::RectangleShape& body) {
		
			if ((int)body.getPosition().x == (int)player.getPosition().x|| (int)body.getPosition().y == (int)player.getPosition().y) {
				std::cout << "Collided!!" << std::endl;
<<<<<<< Updated upstream
				system("CLS");
=======
>>>>>>> Stashed changes
			}
		
	}
	void DRoad::spawnVehicle()
	{
		sf::Clock c;
		srand(unsigned(c.getElapsedTime().asMicroseconds() * 1000));
		Vehicle* v;
		if (this->isFromLeft == 1) {
			if (rand() % 2 == 0) {
				v = new Car(getCenterRoadPosition());
			}
			else v = new Bike(this->getCenterRoadPosition());
			r_vehicle.push_back(v);
		}
		else {
			if (rand() % 2 == 0) {
				v = new Car({ 1280,getCenterRoadPosition().y });
			}
			else v = new Bike({ 1280,this->getCenterRoadPosition().y });
			r_vehicle.push_back(v);
		}
	}
	void DRoad::update(float dt)
	{
		//Updating the timer for enemy spawning
		if (this->r_vehicle.size() < this->maxVehicle)
		{
			this->spawnVehicle();
		}

		//Moving and updating enemies
		for (int i = 0; i < this->r_vehicle.size(); i++)
		{
			this->r_vehicle[i]->vehicle.move(double(100*dt * this->isFromLeft), 0.f);

			this->tryCollide(this->r_vehicle[i]->vehicle);
		
			if (this->isFromLeft == 1 && this->r_vehicle[i]->vehicle.getPosition().x > 1280)
				this->r_vehicle.erase(this->r_vehicle.begin() + i);
			if (this->isFromLeft == -1 && (this->r_vehicle[i]->vehicle.getPosition().x+this->r_vehicle[i]->vehicle.getSize().x) < 0)
				this->r_vehicle.erase(this->r_vehicle.begin() + i);
		}
	}

	

