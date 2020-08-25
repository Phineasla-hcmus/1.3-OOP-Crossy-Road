#ifndef Vehicle_h
#define Vehicle_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../../Framework/game.h"
#include "../Collidable.h"
#include "Player.h"

//class Vehicle :public Collision {
//protected:
//	sf::RectangleShape vehicle;
//	friend class DRoad;
//public:
//	Vehicle(sf::Color color = sf::Color::White, sf::Vector2f position = { 0.f,0.f }, sf::Vector2f size = { 90.f,90.f });
//	virtual void onCollide(Collision& other) = 0;
//	virtual const sf::Vector2f& getPosition() const = 0;
//	virtual void draw(sf::RenderTarget& target) = 0;
//};
//class Car :public Vehicle {
//private:
//	bool m_active;
//public:
//	Car(sf::Vector2f position = { 0.f,0.f });
//	virtual void draw(sf::RenderTarget& target);
//	void onCollide(Collision& other) {
//		m_active = false;
//	}
//	const sf::Vector2f& getPosition() const {
//		return vehicle.getPosition();
//	}
//	static Vehicle* newVehicle(sf::Vector2f origin_pos);
//};
//
//class Truck :public Vehicle {
//private:
//	bool m_active;
//public:
//	Truck(sf::Vector2f position = { 0.f,0.f });
//	void onCollide(Collision& other) {
//		m_active = false;
//	}
//	const sf::Vector2f& getPosition() const {
//		return vehicle.getPosition();
//	}
//	virtual void draw(sf::RenderTarget& target);
//	static Vehicle* newVehicle(sf::Vector2f origin_pos);
//
//};
//
//class Bird :public Vehicle {
//private:
//	bool m_active;
//public:
//	Bird(sf::Vector2f position = { 0.f,0.f });
//	void onCollide(Collision& other) {
//		m_active = false;
//	}
//	const sf::Vector2f& getPosition() const {
//		return vehicle.getPosition();
//	}
//	void draw(sf::RenderTarget& target);
//	static Vehicle* newVehicle(sf::Vector2f origin_pos);
//};

class Vehicle : public Collision {
private:
	sf::RectangleShape m_sprite;
	const sf::Texture& m_texture;
public:
	Vehicle(const sf::Texture&, sf::Vector2f pos = { 0,0 }, sf::Vector2f size = { tile_size,tile_size });
	Vehicle(const sf::Texture&, sf::Vector2f pos = { 0,0 }, float vehicle_length = tile_size);

	const sf::Vector2f& getPosition() const;
	void set_TextureRec(const sf::IntRect& texture_bounds);
	void draw(sf::RenderTarget&) const;
	void move(float speed, float dt_time, int direction);
};
class Car :public Vehicle {
public:
	Car(const sf::Texture& texture, const sf::Vector2f& pos, float car_length);
};
class Truck :public Vehicle {
public:
	Truck(const sf::Texture& texture, const sf::Vector2f& pos, float truck_length);
};

template<typename T>
std::unique_ptr<Vehicle> new_vehicle(const sf::Texture& texture, const sf::Vector2f& pos, float length)
{ 
	return std::make_unique<T>(texture, pos, length);
}
#endif // !Vehicle_h
	

