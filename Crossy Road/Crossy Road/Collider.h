#pragma once
#ifndef COL_H
#define COL_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Collider
{
private:
	RectangleShape& body;
public:
	Collider(RectangleShape& body);
	~Collider();
	bool CheckCollision(Collider& other, float push);
	void Move(float dx, float dy) { body.move(dx, dy); }
	Vector2f getPosition() { return body.getPosition(); }
	Vector2f getHalfSize() { return body.getSize() / 2.0f; }
	Collider GetCollider() { return Collider(body); }
};
#endif

