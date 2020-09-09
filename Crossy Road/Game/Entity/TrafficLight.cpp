#include "TrafficLight.h"
<<<<<<< HEAD

TrafficLight::TrafficLight(sf::Vector2f org_Pos)
{
	this->light.setSize(size);	
	this->light.setPosition(org_Pos);
	this->light.setFillColor(state);
=======
#include <iostream>

TrafficLight::TrafficLight(sf::Vector2f org_Pos)
{
	red_light = asset::texture().get("red", "png");
	green_light = asset::texture().get("green", "png");
	this->light.setSize(size);	
	this->light.setPosition(org_Pos);
	light.setTexture(&green_light);
>>>>>>> new-vehicle
}

void TrafficLight::turnRed()
{
	state = (sf::Color::Red);
<<<<<<< HEAD
	this->light.setFillColor(state);
=======
	light.setTexture(&red_light);
>>>>>>> new-vehicle
}

void TrafficLight::turnGreen()
{
	state = (sf::Color::Green);
<<<<<<< HEAD
	this->light.setFillColor(state);
=======
	light.setTexture(&green_light);
>>>>>>> new-vehicle
}

sf::Color TrafficLight::getLightState()
{
	return state;
}

void TrafficLight::draw(sf::RenderTarget& target)
{
	target.draw(this->light);
<<<<<<< HEAD
}


=======
	//std::cout << "draw light\n";
}
>>>>>>> new-vehicle
