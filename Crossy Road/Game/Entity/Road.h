#ifndef _road_h
#define _road_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vehicle.h"
#include "Player.h"

using CollisionResult = std::pair<int, std::vector<sf::Vector2f>>;
class DRoad {
private:
	sf::RectangleShape lane;
	float width;
	float distance;
	std::vector<Vehicle*> r_vehicle;	
	int maxVehicle;
	
	float m_speed;
	Player& m_player;
	sf::Vector2f m_pos;
	float speed;
	int isFromLeft = 1;
	
	

public:
	DRoad(sf::Vector2f pos, float speed, int isFromLeft, Player& player);
	void initVehicle();
	void initVar(float width = 90, float distance = 90);
	void initShape(sf::Vector2f position = { 0,0 });
	float getDistance();
	void update(float dt,int level);
	void draw(sf::RenderTarget& target);
	sf::Vector2f getCenterRoadPosition();
	void spawnVehicle();
	CollisionResult tryCollideWithPlayer();
};
#endif // !_road_h
