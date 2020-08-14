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
<<<<<<< Updated upstream
    Collider(float width, float height);

    bool tryCollideWith(Collider& other);
    sf::FloatRect getBox() const;

    virtual const sf::Vector2f& getPosition() const = 0;
    virtual void onCollide(Collider& other) = 0;

private:
    sf::Vector2f m_size;
=======
	Collider(RectangleShape body);
	Collider(Sprite& sprite, float x, float y, float width, float height);
	virtual ~Collider();
	
	bool checkInterect(const FloatRect& fr);
	void Update();
	void Render(RenderTarget& target);
private:
	Sprite& sprite;
	RectangleShape hitbox;
	float offsetX, offsetY;
	
	
>>>>>>> Stashed changes
};
#endif

