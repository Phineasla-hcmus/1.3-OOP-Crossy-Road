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
    Collider(float width, float height);

    bool tryCollideWith(Collider& other);
    sf::FloatRect getBox() const;

    virtual const sf::Vector2f& getPosition() const = 0;
    virtual void onCollide(Collider& other) = 0;

private:
    sf::Vector2f m_size;
};
#endif

