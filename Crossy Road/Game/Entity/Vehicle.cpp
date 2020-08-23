#include "Vehicle.h"
#include "../../Framework/Util/random.h"


Vehicle::Vehicle(sf::Color color, sf::Vector2f position, sf::Vector2f size) :Collision(size.x, size.y)
{
	this->vehicle.setPosition(position);
	this->vehicle.setSize(size);
	this->vehicle.setFillColor(color);
	//this->enemy.setOutlineColor(sf::Color::Green);
	//this->enemy.setOutlineThickness(1.f);
}

Car::Car(sf::Vector2f position) :m_Active(true), Vehicle(sf::Color::White, sf::Vector2f(20.f, 20.f), sf::Vector2f(90.f, 70.f)) {

	this->vehicle.setSize(sf::Vector2f(90.f, 70.f));

	this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));
	this->vehicle.setFillColor(sf::Color::Blue);	

};
	void Car::draw(sf::RenderTarget& target) {
		target.draw(this->vehicle);
	}

	Vehicle* Car::newVehicle(sf::Vector2f origin_pos)
	{
		return new Car(origin_pos);
	}

	Bike::Bike(sf::Vector2f position) : m_Active(true),Vehicle(sf::Color::Yellow, sf::Vector2f(15.f, 15.f), sf::Vector2f(90.f, 90.f)) {
		this->vehicle.setSize(sf::Vector2f(90.f, 90.f));
		this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));
		this->vehicle.setFillColor(sf::Color::Yellow);
		
	};
	void Bike::draw(sf::RenderTarget& target) {
		target.draw(this->vehicle);
	}

	Vehicle* Bike::newVehicle(sf::Vector2f origin_pos)
	{
		return new Bike(origin_pos);
	}
	
	Bird::Bird(sf::Vector2f position) :m_Active(true),Vehicle(sf::Color::Yellow, sf::Vector2f(15.f, 15.f), sf::Vector2f(100.f, 50.f)) {
		this->vehicle.setSize(sf::Vector2f(90.f, 50.f));
		this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));
		this->vehicle.setFillColor(sf::Color::Magenta);
	};
	void Bird::draw(sf::RenderTarget& target) {
		target.draw(this->vehicle);
	}

	Vehicle* Bird::newVehicle(sf::Vector2f origin_pos)
	{
		return new Bird(origin_pos);
	}


