#ifndef _road_h
#define _road_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vehicle.h"


class DRoad {
private:
	sf::RectangleShape lane;
	float width;
	float distance;
	std::vector<Vehicle*> r_vehicle;	
	int maxVehicle;
	float speed;
	int isFromLeft;
	sf::Clock start;
	

public:
	DRoad(sf::Vector2f pos = { 0.f,0.f }, float speed = 100, int isFromLeft = 1);
	void initVehicle();
	void initVar(float width = 90, float distance = 90);
	void initShape(sf::Vector2f position = { 0,0 });
	float getDistance();
	void update(float dt,int level);
	void draw(sf::RenderTarget& target);
	sf::Vector2f getCenterRoadPosition();
	void spawnVehicle();
	
};
#endif // !_road_h
