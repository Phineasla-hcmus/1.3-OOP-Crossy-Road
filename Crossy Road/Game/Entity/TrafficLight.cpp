#include "TrafficLight.h"
#include <iostream>

TrafficLight::TrafficLight(sf::Vector2f org_Pos)
{
	this->light.setSize(size);	
	this->light.setPosition(org_Pos);
	this->light.setFillColor(state);
}

void TrafficLight::turnRed()
{
	state = (sf::Color::Red);
	this->light.setFillColor(state);
}

void TrafficLight::turnGreen()
{
	state = (sf::Color::Green);
	this->light.setFillColor(state);
}

sf::Color TrafficLight::getLightState()
{
	return state;
}

void TrafficLight::draw(sf::RenderTarget& target)
{
	target.draw(this->light);
	//std::cout << "draw light\n";
}