#pragma once

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>

#include "../Collidable.h"
#include "../../Framework/Util/Animation.h"

namespace CrossRoad
{
    /**
        Represents the player
    */
    class Player : public Collidable
    {
    public:
        constexpr static int WIDTH = 44;
        constexpr static int HEIGHT = 32;

        Player();

        void inputKeyPress();
        void update(float dt);
        void draw(sf::RenderTarget& target);           

        const sf::Vector2f& getPosition() const;
        void onCollide(Collidable& other) override;
     
        bool isAlive() const;

    private:
        void restart();

        sf::RectangleShape people;
        Animation death_Animation;
        sf::Vector2f v_speed;
        sf::Clock m_deathTimer;

        bool is_Alive = true;        

        sf::Sound death_Sound;
    };
}