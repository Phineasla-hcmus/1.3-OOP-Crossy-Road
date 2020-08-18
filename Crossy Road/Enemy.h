#pragma once
#include <SFML/Graphics.hpp>

#include "Collidable.h"

    /*
        Class to represent a single invader
    */
class Object : public Collidable
{
public:
    enum class Type
    {
        Bus,Car,Tree,Animal
    };

    Object(const sf::Vector2f& initialLocation, Type type/*,sf::RectangleShape obj*/);

    void move(float x, float y);

    const sf::Vector2f& getPosition() const;
    bool isAlive() const;
    Type getType() const;

    void onCollide(Collidable& other) override;

    void makeAlive()
    {
        m_isAlive = true;
        m_location = m_initialPosition;
    }

private:
    const sf::Vector2f m_initialPosition;
    sf::Vector2f m_location;
    bool m_isAlive = true;
    Type m_type;
    sf::RectangleShape rect;
public:
    constexpr static float WIDTH = 48;
    constexpr static float HEIGHT = 32;
};
