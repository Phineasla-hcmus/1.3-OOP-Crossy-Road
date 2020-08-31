#ifndef Vehicle_h
#define Vehicle_h

#include "../../PCH.h"
#include "../Collidable.h"


class Vehicle : public Collision {
private:
	bool m_active;
	sf::RectangleShape m_sprite;
	int shake = 3;
public:
	Vehicle(sf::Vector2f pos, const sf::Texture&);
	Vehicle(sf::Vector2f pos, const sf::Texture&, sf::IntRect textureBound);

	const sf::Vector2f& getPosition()	const { return m_sprite.getPosition(); };
	void	onCollide(Collision& other) { m_active = false; };
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
	

