#ifndef trafflight_h
#define trafflight_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class TrafficLight {
private:
	sf::RectangleShape light;
	sf::Vector2f size = { 30.f,30.f };
	sf::Color state=(sf::Color::Green);
	sf::Clock time;	
public:
	TrafficLight(sf::Vector2f org_Pos = { 0.f,0.f });
	void turnRed();
	void turnGreen();
	sf::Color getLightState();
	void draw(sf::RenderTarget& target);
};


#endif