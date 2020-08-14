#pragma once
#include <SFML/Graphics.hpp>

#include "Collider.h"
class Player
{
public:
	Player();
	//Player(sf::RectangleShape& body);
	virtual~Player();

	void move(const float x, const float y);
	/*void Draw(sf::RenderWindow window);*/
	void Render(RenderTarget& target);
	void Update();
	Collider getCollider() { return Collider(body); };
private:
	
	float movementSpeed;
	sf::RectangleShape body;
	
};

