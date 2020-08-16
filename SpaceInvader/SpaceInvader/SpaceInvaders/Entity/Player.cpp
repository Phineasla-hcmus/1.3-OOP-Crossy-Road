#include "Player.h"
#include "../DisplayInfo.h"
#include "../../Framework/ResourceManager/ResourceHolder.h"

namespace CrossRoad
{
    namespace
    {
        constexpr float BASE_Y = (float)Display::HEIGHT - 40.0f;
        constexpr float BASE_X = (float)Display::WIDTH - 40.0f;
    }

    Player::Player()
        : Collidable(44, 32)
        , death_Animation(11, 8)
    {
        people.setSize({ 44, 32 });
        people.setPosition({ Display::WIDTH / 2, BASE_Y });
        //people.setTexture(&ResourceHolder::get().textures.get("si/player"));
        //people.setTextureRect({ 0, 0, 11, 8 });

        /*for (int i = 0; i < 20; i++) {
            death_Animation.addFrame(((i % 2) + 1), sf::seconds(0.1f));
        }*/

        //death_Sound.setBuffer(ResourceHolder::get().soundBuffers.get("si/explosion"));

    }

    void Player::restart()
    {
        v_speed *= 0.0f;
        //people.setTextureRect({ 0, 0, 11, 8 });
        is_Alive = true;        
        people.setPosition({ Display::WIDTH / 2, BASE_Y });
    }

    void Player::inputKeyPress()
    {
        using Key = sf::Keyboard::Key;
        auto keyDown = [](sf::Keyboard::Key k) {
            return sf::Keyboard::isKeyPressed(k);
        };

        float speed = 20;
        if (keyDown(Key::A)) {
            v_speed.x -= speed;
        }
        else if (keyDown(Key::D)) {
            v_speed.x += speed;
        }
        else if (keyDown(Key::W)) {
            v_speed.y -= speed;
        }
        else if (keyDown(Key::S)) {
            v_speed.y += speed;
        }
    }

    void Player::update(float dt)
    {
        if (is_Alive) {
            auto w = people.getGlobalBounds().width;
            auto h = people.getGlobalBounds().height;
            people.move(v_speed * dt);
            v_speed *= 0.95f;
            //if player move out of bound
            
            //Left
            if (this->people.getGlobalBounds().left <= 0.f)
                this->people.setPosition(0.f, this->people.getGlobalBounds().top);
            //Right
            if (this->people.getGlobalBounds().left + this->people.getGlobalBounds().width >= 1280)
                this->people.setPosition(1280- this->people.getGlobalBounds().width, this->people.getGlobalBounds().top);
            //Top
            if (this->people.getGlobalBounds().top <= 0.f)
                this->people.setPosition(this->people.getGlobalBounds().left, 0.f);
            //Bottom
            if (this->people.getGlobalBounds().top + this->people.getGlobalBounds().height >= 720)
                this->people.setPosition(this->people.getGlobalBounds().left, 720 - this->people.getGlobalBounds().height);
        }
    }

    void Player::draw(sf::RenderTarget& target)
    {
        if (!is_Alive) {
            people.setTextureRect(death_Animation.getFrame());
        }
        else
            target.draw(people);
        
    }

 
    const sf::Vector2f & Player::getPosition() const
    {
        return people.getPosition();
    }

    void Player::onCollide(Collidable& other)
    {
        is_Alive = false;
        m_deathTimer.restart();
        death_Sound.play();
    }


    bool Player::isAlive() const
    {
        return is_Alive;
    }   

}