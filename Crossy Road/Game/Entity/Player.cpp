#include "Player.h"
#include "../world.h"

    Player::Player() :Collision(90.f,90.f)
    {
        sf::Vector2f size_player = { 90.f,90.f };
        people.setSize(size_player);        
        people.setPosition(this->origin_pos);
       // people.setTextureRect({ 0, 0, 11, 8 });
        
    }

    void Player::restart()
    {
        v_speed *= 0.0f;
      //  people.setTextureRect({ 0, 0, 11, 8 });//
        is_Alive = true;        
        people.setPosition(this->origin_pos);
    }

    void Player::inputKeyPress()
    {
        using Key = sf::Keyboard::Key;
        auto keyDown = [](sf::Keyboard::Key k) {
            return sf::Keyboard::isKeyPressed(k);
        };
        
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
            people.move(v_speed );
            v_speed *= 0.f;
            //if player move out of bound
            
            //Left
            if (this->people.getGlobalBounds().left <= 0.f)
                this->people.setPosition(0.f, this->people.getGlobalBounds().top);
            //Right
            if (this->people.getGlobalBounds().left + this->people.getGlobalBounds().width >= 1280)
                this->people.setPosition(1280- this->people.getGlobalBounds().width, this->people.getGlobalBounds().top);
            //Top
            if (this->people.getGlobalBounds().top <= 0.f) {
                this->people.setPosition(this->people.getGlobalBounds().left, 720 - this->people.getGlobalBounds().height);
                World::levelUp();
            }
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

   


    bool Player::isAlive() const
    {
        return is_Alive;
    }   

