#pragma once
#ifndef COL_H
#define COL_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Collider
{
public:
	Collider(Sprite& sprite, float x, float y, float width, float height);
	virtual ~Collider();
	
	bool checkInterect(const FloatRect& fr);
	void Update();
	void Render(RenderTarget& target);
private:
	Sprite& sprite;
	RectangleShape hitbox;
	float offsetX, offsetY;
	
	
};
#endif

