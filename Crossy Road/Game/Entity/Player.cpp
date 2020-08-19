#include "Player.h"

    Player::Player()       
    {
        people.setSize({ 20, 20 });
        people.setPosition({640, 720-10});
        
    }

    void Player::restart()
    {
        v_speed *= 0.0f;
        //people.setTextureRect({ 0, 0, 11, 8 });
        is_Alive = true;        
        people.setPosition({ 640,720-10 });
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
            //people.setTextureRect(death_Animation.getFrame());
        }
        else
            target.draw(people);
        
    }

 
    const sf::Vector2f & Player::getPosition() const
    {
        return people.getPosition();
    }

   


    bool Player::isAlive() const
    {
        return is_Alive;
    }   

