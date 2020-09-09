#ifndef trafflight_h
#define trafflight_h
<<<<<<< HEAD
=======
#include"../../Framework/AssetManager/asset.h"
>>>>>>> new-vehicle
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TrafficLight {
private:
<<<<<<< HEAD
=======
	sf::Texture red_light;
	sf::Texture green_light;
>>>>>>> new-vehicle
	sf::RectangleShape light;
	sf::Vector2f size = { 30.f,30.f };
	sf::Color state=(sf::Color::Green);
	sf::Clock time;	
public:
<<<<<<< HEAD
	TrafficLight(sf::Vector2f org_Pos = { 0.f,0.f });
	void turnRed();
	void turnGreen();
	sf::Color getLightState();
	void draw(sf::RenderTarget& target);	
=======
	TrafficLight(sf::Vector2f pos = { 10.f,10.f });
	void turnRed();
	void turnGreen();
	sf::Color getLightState();
	void draw(sf::RenderTarget& target);
>>>>>>> new-vehicle
};


#endif