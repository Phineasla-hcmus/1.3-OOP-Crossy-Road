#pragma once
<<<<<<< Updated upstream

#include <SFML/Graphics.hpp>
#include "Collidable.h"
    /*
        Class to represent a single invader
    */
class Object : public Collidable
{
public:
    /*enum class Type
    {
        Octopus, Crab, Squid,
    };*/

    Object(const sf::Vector2f& initialLocation/*, Type type*/);

    void move(float x, float y);

    const sf::Vector2f& getPosition() const;
    bool isAlive() const;
   /* Type getType() const;*/

    void onCollide(Collidable& other) override;

    void makeAlive()
    {
        m_isAlive = true;
=======
#ifndef OBJ_H
#define OBJ_H
#include <SFML\Graphics.hpp>
#include "Crossy Road/Collider.h"

class Object : public Collider
{
public:
    enum class Type
    {
        Animal, Car, Bus,tree
    };

    Object(const sf::Vector2f& initialLocation);

    void move(float x);

    const sf::Vector2f& getPosition() const;
    bool isActive() const;


    void onCollide(Collider& other) override;

    Type getType() const;
    void makeAlive()
    {
        m_isActive = true;
>>>>>>> Stashed changes
        m_location = m_initialPosition;
    }

private:
    const sf::Vector2f m_initialPosition;
    sf::Vector2f m_location;
<<<<<<< Updated upstream
    bool m_isAlive = false;
 
   /* Type m_type;*/

public:
   
    constexpr static float WIDTH = 48.f;
    constexpr static float HEIGHT = 32.f;
    sf::RectangleShape rect;
};
=======
    bool m_isActive = false;
    RectangleShape body;

public:
    constexpr static float WIDTH = 48;
    constexpr static float HEIGHT = 32;
};
#endif
>>>>>>> Stashed changes
