#pragma once

#include <SFML/Graphics.hpp>


    class Collision
    {
    public:
        Collision(float width, float height);

        bool tryCollideWith(Collision& other);
        sf::FloatRect getBox() const;

        virtual const sf::Vector2f& getPosition() const = 0;
        virtual void onCollide(Collision& other);

    private:
        sf::Vector2f m_size;
    };
