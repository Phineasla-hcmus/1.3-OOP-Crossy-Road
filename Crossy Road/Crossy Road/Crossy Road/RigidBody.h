#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"

class RigidBody
{
public:
	RigidBody(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~RigidBody();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
private:
	sf::RectangleShape body;
};

