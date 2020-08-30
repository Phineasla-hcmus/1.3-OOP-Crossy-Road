#ifndef _road_h
#define _road_h
#include "../../PCH.h"
#include "Vehicle.h"
//class DRoad {
//private:
//	sf::RectangleShape lane;
//	float width;
//	float distance;
//	//std::vector<Vehicle*> r_vehicle;	
//
//	float speed;
//	Player& m_player;
//	sf::Vector2f m_pos;
//	int isFromLeft ;
//	int num_Vehicle ;
//	
//	//typedef Vehicle* (*new_vehicle)(sf::Vector2f origin_pos);
//
//public:
//	enum direction {
//		left = 1,
//		right = -1
//	};
//	//DRoad(int num_Vehicle,int rand_startPos,int rand_typeVehicle,sf::Vector2f pos, float speed, int isFromLeft, Player& player);
//	//void initVehicle(int k=0, int rand_startPos=0);
//	//void initVar(float width = 90, float distance = 90);
//	//void initShape(sf::Vector2f position = { 0,0 });
//	//float getDistance();
//	//void update(float dt,int level);
//	//void draw(sf::RenderTarget& target);
//	//sf::Vector2f getCenterRoadPosition();
//	//void spawnVehicle();
//	//CollisionResult tryCollideWithPlayer();
//
//	//static Vehicle* initVehicle_rand(int i,sf::Vector2f origin_pos)
//	//{
//	//	int k = i % 3;
//	//	new_vehicle vehicle_rand[] =
//	//	{
//	//		Car::newVehicle,
//	//		Truck::newVehicle,
//	//		Bird::newVehicle
//	//	};
//	//	
//	//	return vehicle_rand[k](origin_pos);
//	//}
//
//};

constexpr auto HIDDEN_VEHICLE	= 2;
constexpr auto EXTRA_PIXEL		= 320;
constexpr auto LEFT_BOUND		= -EXTRA_PIXEL;
constexpr auto RIGHT_BOUND		= SCREEN_WIDTH + EXTRA_PIXEL;
constexpr auto EXTEND_WIDTH		= SCREEN_WIDTH + EXTRA_PIXEL * 2;
/*
BOUND			_____________				BOUND
||				|			|				||
||EXTRA_PIXEL	|	SCREEN	|EXTRA_PIXEL	||
||				|___________|				||
<---------------EXTEND_WIDTH----------------->
*/

constexpr float VEHICLE_SIZE	= 85;
class Vehicle;
using CollisionResult = std::pair<int, std::vector<sf::Vector2f>>;
//function for init new vehicle
using vehicle_func = std::function < std::unique_ptr<Vehicle>(sf::Vector2f pos, const sf::Texture& texture, sf::IntRect textureBound) >;
class Lane {
public:
	enum direction {
		left = 1,
		right = -1,
	};
	Lane(const sf::Vector2f road_pos, const direction, float speed);
	void		initVehicle(size_t, random&);
	void		setVehicleType(vehicle_func, sf::Texture& vehicle, sf::IntRect vehicle_bound);
	size_t		getVehicleSize() const;
	Vehicle&	getVehicle(size_t);
	void		draw(sf::RenderTarget& target);
	void		update(unsigned& level,float dt);
private:
	const sf::Vector2f						m_pos = { 0.f,0.f };
	const direction							m_dir=left;
	float									m_speed = 0;
	std::vector<std::unique_ptr<Vehicle>>	m_vehicles;
	sf::Texture*							m_vehicles_texture = nullptr;
	sf::IntRect								m_texture_bound;
	vehicle_func							m_init_func;
};
#endif // !_road_h
