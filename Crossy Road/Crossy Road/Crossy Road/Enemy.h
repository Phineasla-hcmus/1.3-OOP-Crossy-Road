#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Enemy
{
public:
<<<<<<< Updated upstream
	Enemy(float x, float y, RectangleShape rec);
=======
	Enemy(float x, float y, RenderWindow& window);
>>>>>>> Stashed changes

	virtual~Enemy();
	void Update(RenderWindow& window);
	const FloatRect getBounds() const;
<<<<<<< Updated upstream
=======
	void Render(RenderTarget& target);
	Collider getCollider() { return Collider(body); };
>>>>>>> Stashed changes
private:
	RectangleShape body;
	float speed;
	int row;
	void initSpeed();
	void initRow();
};
#endif

