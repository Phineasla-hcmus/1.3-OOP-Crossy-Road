#ifndef _road_h
#define _road_h
#include "../../PCH.h"
#include "Vehicle.h"
#include "TrafficLight.h"

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
	Lane(Lane&&) = default;
	Lane(const sf::Vector2f road_pos, const direction, float speed);
	//Lane(Lane&&) = default;
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
	TrafficLight							m_light;

	/*float									m_time_running_origin = rand() % 40 * 1.0 / 10;
	sf::Time								m_red_time = sf::seconds(1.f + (rand() % 20 * 1.0 / 10));
	sf::Time								m_green_time = sf::seconds(3.f + (rand() % 40 * 1.0 / 10));
	sf::Clock								m_time;
	sf::Time								m_start_Point = m_time.getElapsedTime();*/
};
#endif // !_road_h
