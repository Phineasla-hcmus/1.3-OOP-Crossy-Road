#include "TrafficLight.h"

TrafficLight::TrafficLight(sf::Vector2f org_Pos)
{
	red_light = asset::texture().get("red", "png");
	green_light = asset::texture().get("green", "png");
	this->light.setSize(size);	
	this->light.setPosition(org_Pos);
	light.setTexture(&green_light);
}

void TrafficLight::turnRed()
{
	state = (sf::Color::Red);
	light.setTexture(&red_light);
}

void TrafficLight::turnGreen()
{
	state = (sf::Color::Green);
	light.setTexture(&green_light);
}

sf::Color TrafficLight::getLightState()
{
	return state;
}

void TrafficLight::draw(sf::RenderTarget& target)
{
	target.draw(this->light);
}