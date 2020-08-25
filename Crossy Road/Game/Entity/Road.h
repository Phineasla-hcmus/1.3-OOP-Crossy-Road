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
	//std::vector<Vehicle*> r_vehicle;	

	float m_speed;
	Player& m_player;
	sf::Vector2f m_pos;
	int isFromLeft ;
	int num_Vehicle ;
	
	//typedef Vehicle* (*new_vehicle)(sf::Vector2f origin_pos);

public:
	enum direction {
		left = 1,
		right = -1
	};
	//DRoad(int num_Vehicle,int rand_startPos,int rand_typeVehicle,sf::Vector2f pos, float speed, int isFromLeft, Player& player);
	//void initVehicle(int k=0, int rand_startPos=0);
	//void initVar(float width = 90, float distance = 90);
	//void initShape(sf::Vector2f position = { 0,0 });
	//float getDistance();
	//void update(float dt,int level);
	//void draw(sf::RenderTarget& target);
	//sf::Vector2f getCenterRoadPosition();
	//void spawnVehicle();
	//CollisionResult tryCollideWithPlayer();

	//static Vehicle* initVehicle_rand(int i,sf::Vector2f origin_pos)
	//{
	//	int k = i % 3;
	//	new_vehicle vehicle_rand[] =
	//	{
	//		Car::newVehicle,
	//		Truck::newVehicle,  // weighted towards FOO
	//		Bird::newVehicle
	//	};
	//	
	//	return vehicle_rand[k](origin_pos);
	//}

};
#endif // !_road_h
