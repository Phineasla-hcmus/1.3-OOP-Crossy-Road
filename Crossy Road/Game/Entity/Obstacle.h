#ifndef Vehicle_h
#define Vehicle_h

#include "../../PCH.h"
#include "../Collidable.h"


class Obstacle : public Collision {
private:
	bool m_active;
	sf::RectangleShape m_sprite;
public:
	Obstacle(sf::Vector2f pos, const sf::Texture&);
	Obstacle(sf::Vector2f pos, const sf::Texture&, sf::IntRect textureBound);

	const sf::Vector2f& getPosition()	const { return m_sprite.getPosition(); };
	void onCollide(Collision& other) { m_active = false; };
	const sf::Vector2f& getSize()		const;
	void setTexture(const sf::Texture&, const sf::IntRect&);
	void setTexture(const sf::Texture&, bool resetRect = false);
	void setTextureRec(const sf::IntRect&);
	void setSize(const sf::Vector2f&);
	void setScale(const sf::Vector2f&);
	void draw(sf::RenderTarget&) const;
	void move(float speed);
	void resetPosition(sf::Vector2f position);
};
class Car :public Obstacle {
public:
	Car(sf::Vector2f pos, const sf::Texture&);
	Car(sf::Vector2f pos, const sf::Texture&, sf::IntRect textureBound);
};
class Truck :public Obstacle {
public:
	Truck(sf::Vector2f pos, const sf::Texture&);
	Truck(sf::Vector2f pos, const sf::Texture&, sf::IntRect textureBound);
};
class Animal :public Obstacle {
public:
	Animal(sf::Vector2f pos, const sf::Texture&);
	Animal(sf::Vector2f pos, const sf::Texture&, sf::IntRect textureBound);
};

template<typename T>
std::unique_ptr<Obstacle> new_vehicle(sf::Vector2f pos, const sf::Texture& texture, sf::IntRect textureBound)
{
	return std::make_unique<T>(pos, texture, textureBound);
}
#endif // !Vehicle_h
	

