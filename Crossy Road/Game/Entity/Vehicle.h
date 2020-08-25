#ifndef Vehicle_h
#define Vehicle_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "../Collidable.h"

	
class Vehicle :public Collision {
protected:
	sf::RectangleShape vehicle;
	friend class DRoad;
public:
	Vehicle(sf::Color color = sf::Color::White, sf::Vector2f position = { 0.f,0.f }, sf::Vector2f size = { 90.f,90.f });
	virtual void onCollide(Collision& other) = 0;
	virtual const sf::Vector2f& getPosition() const = 0;
	virtual void draw(sf::RenderTarget& target) = 0;
};
template<typename T>
std::unique_ptr<Vehicle> new_vehicle() { return std::make_unique<T>(); }
class Car :public Vehicle {
private:
	bool m_active;
public:
	Car(sf::Vector2f position = { 0.f,0.f });
	virtual void draw(sf::RenderTarget& target);
	void onCollide(Collision& other) {
		m_active = false;
	}
	const sf::Vector2f& getPosition() const {
		return vehicle.getPosition();
	}
	static Vehicle* newVehicle(sf::Vector2f origin_pos);
};

class Truck :public Vehicle {
private:
	bool m_active;
public:
	Truck(sf::Vector2f position = { 0.f,0.f }) ;
	void onCollide(Collision& other) {
		m_active = false;
	}
	const sf::Vector2f& getPosition() const {
		return vehicle.getPosition();
	}
	virtual void draw(sf::RenderTarget& target);
	static Vehicle* newVehicle(sf::Vector2f origin_pos);

};

class Bird :public Vehicle {
private:
	bool m_active;
public:
	Bird(sf::Vector2f position = { 0.f,0.f });
	void onCollide(Collision& other) {
		m_active = false;
	}
	const sf::Vector2f& getPosition() const {
		return vehicle.getPosition();
	}
	void draw(sf::RenderTarget& target);
	static Vehicle* newVehicle(sf::Vector2f origin_pos);
};


#endif // !Vehicle_h
	

