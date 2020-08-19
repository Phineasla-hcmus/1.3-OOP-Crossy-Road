#ifndef _road_h
#define _road_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vehicle.h"
#include"../World.h"

class World;
class DRoad {
private:
	sf::RectangleShape lane;
	float width;
	float distance;
	std::vector<Vehicle*> r_vehicle;
	float vehicleSpawnTimer;
	float vehicleSpawnTimerMax;
	int maxVehicle;
	float speed;
	int isFromLeft;
	Player& player;
public:
	DRoad(sf::Vector2f pos, float speed, int isFromLeft, Player& m_player);
	void initVehicle();
	void initVar(float width = 90, float distance = 90);
	void initShape(sf::Vector2f position = { 0,0 });
	float getDistance();
	void update(float dt);
	void draw(sf::RenderTarget& target);
	sf::Vector2f getCenterRoadPosition();
	void spawnVehicle();
	
	void tryCollide(sf::RectangleShape& body);
};
#endif // !_road_h
