#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Enemy
{
public:
	Enemy(float x, float y, RectangleShape rec);

	virtual~Enemy();
	void Update(RenderWindow& window);
	const FloatRect getBounds() const;
private:
	RectangleShape body;
	float speed;
	int row;
	void initSpeed();
	void initRow();
};
#endif

