#include "Vehicle.h"


	Vehicle::Vehicle(sf::Color color, sf::Vector2f position,  sf::Vector2f size):Collision(size.x,size.y)
	{
		this->vehicle.setPosition(position);
		this->vehicle.setSize(size);
		this->vehicle.setFillColor(color);
		//this->enemy.setOutlineColor(sf::Color::Green);
		//this->enemy.setOutlineThickness(1.f);
	}

	Car::Car(sf::Vector2f position) : Vehicle(sf::Color::White, sf::Vector2f(20.f, 20.f),sf::Vector2f(90.f,70.f)) {
		
		this->vehicle.setSize(sf::Vector2f(90.f, 70.f));
	
		this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));
		
		auto k = rand() % 5;
		//set color

		switch (k)
		{
		case 0:
			this->vehicle.setFillColor(sf::Color::Blue);
			break;
		case 1:
			this->vehicle.setFillColor(sf::Color::Yellow);
			break;
		case 2:
			this->vehicle.setFillColor(sf::Color::Green);
			break;
		case 3:
			this->vehicle.setFillColor(sf::Color::Magenta);
			break;
		case 4:
			this->vehicle.setFillColor(sf::Color::Red);
			break;
		default:
			this->vehicle.setFillColor(sf::Color::White);
			break;
		}

	};
	void Car::draw(sf::RenderTarget& target) {
		target.draw(this->vehicle);
	}

	Bike::Bike(sf::Vector2f position) :Vehicle(sf::Color::Yellow, sf::Vector2f(15.f, 15.f), sf::Vector2f(90.f, 90.f)) {
		this->vehicle.setSize(sf::Vector2f(90.f, 90.f));
		this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));
		
		
		auto k = rand() % 5;
		//set color
		switch (k)
		{
		case 0:
			this->vehicle.setFillColor(sf::Color::Blue);
			break;
		case 1:
			this->vehicle.setFillColor(sf::Color::Yellow);
			break;
		case 2:
			this->vehicle.setFillColor(sf::Color::Green);
			break;
		case 3:
			this->vehicle.setFillColor(sf::Color::Magenta);
			break;
		case 4:
			this->vehicle.setFillColor(sf::Color::Red);
			break;
		default:
			this->vehicle.setFillColor(sf::Color::White);
			break;
		}
	};
	void Bike::draw(sf::RenderTarget& target) {
		target.draw(this->vehicle);
	}
	
	Bird::Bird(sf::Vector2f position) :Vehicle(sf::Color::Yellow, sf::Vector2f(15.f, 15.f), sf::Vector2f(100.f, 50.f)) {
		this->vehicle.setSize(sf::Vector2f(100.f, 50.f));
		this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));


		auto k = rand() % 5;
		//set color
		switch (k)
		{
		case 0:
			this->vehicle.setFillColor(sf::Color::Blue);
			break;
		case 1:
			this->vehicle.setFillColor(sf::Color::Yellow);
			break;
		case 2:
			this->vehicle.setFillColor(sf::Color::Green);
			break;
		case 3:
			this->vehicle.setFillColor(sf::Color::Magenta);
			break;
		case 4:
			this->vehicle.setFillColor(sf::Color::Red);
			break;
		default:
			this->vehicle.setFillColor(sf::Color::White);
			break;
		}
	};
	void Bird::draw(sf::RenderTarget& target) {
		target.draw(this->vehicle);
	}


