#pragma once
#include <SFML\Graphics.hpp>
#include "Crossy Road/Collider.h"

class Enemy : public Collider
{
public:
    enum class Type
    {
        Octopus, Crab, Squid,
    };

    Enemy(const sf::Vector2f& initialLocation);

    void move(float x);

    const sf::Vector2f& getPosition() const;
    bool isActive() const;


    void onCollide(Collider& other) override;

    void makeAlive()
    {
        m_isActive = true;
        m_location = m_initialPosition;
    }

private:
    const sf::Vector2f m_initialPosition;
    sf::Vector2f m_location;
    bool m_isActive = false;
    RectangleShape body;
};
