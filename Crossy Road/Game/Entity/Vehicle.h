#ifndef Vehicle_h
#define Vehicle_h

//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include "../../Framework/Game.h"
//#include "../Collidable.h"

#include "../../PCH.h"
#include "../Collidable.h"


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
public:
	Vehicle(sf::Vector2f pos, const sf::Texture&);
	Vehicle(sf::Vector2f pos, const sf::Texture&, sf::IntRect textureBound);

	const sf::Vector2f& getPosition()	const;
	const sf::Vector2f& getSize()		const;
	void setTexture(const sf::Texture&, const sf::IntRect&);
	void setTexture(const sf::Texture&, bool resetRect = false);
	void setTextureRec(const sf::IntRect&);
	void setSize(const sf::Vector2f&);
	void setScale(const sf::Vector2f&);
	void draw(sf::RenderTarget&) const;
	void move(float speed);
};
class Car :public Vehicle {
public:
	Car(sf::Vector2f pos, const sf::Texture&);
	Car(sf::Vector2f pos, const sf::Texture&, sf::IntRect textureBound);
};
class Truck :public Vehicle {
public:
	Truck(sf::Vector2f pos, const sf::Texture&);
	Truck(sf::Vector2f pos, const sf::Texture&, sf::IntRect textureBound);
};

template<typename T>
std::unique_ptr<Vehicle> new_vehicle(sf::Vector2f pos, const sf::Texture& texture, sf::IntRect textureBound)
{
	return std::make_unique<T>(pos, texture, textureBound);
}
#endif // !Vehicle_h
	

