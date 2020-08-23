#include "Player.h"
#include "../world.h"

Player::Player() :Collision(90.f, 90.f)
{
    sf::Vector2f size_player = { 90.f,90.f };
    people.setSize(size_player);
    people.setPosition(this->origin_pos);
    player_texture.loadFromFile("Assets\\textures\\player_sprite_2.png");
    people.setTexture(&player_texture);
    people.setTextureRect(sf::IntRect{ 0,192,64,64 });
}

    void Player::restart()
    {
        v_speed *= 0.0f;
        people.setTextureRect(sf::IntRect{ 0,192,64,64 });
        is_Alive = true;        
        people.setPosition(this->origin_pos);
    }

    void Player::inputKeyPress()
    {

        using Key = sf::Keyboard::Key;
        auto keyDown = [](sf::Keyboard::Key k) {
            return sf::Keyboard::isKeyPressed(k);
        };
        sf::Clock clock;
        if (keyDown(Key::A)) {
            clock.restart();
            people.setTextureRect(sf::IntRect{ 0,64,64,64 });
            /* people.setTextureRect(sf::IntRect{ 64,64,64,64 });*/
            v_speed.x -= speed;
            if (clock.getElapsedTime().asSeconds() > 0.01f)
                v_speed.x = 0.f;
        }
        else if (keyDown(Key::D)) {
            clock.restart();
            people.setTextureRect(sf::IntRect{ 0,128,64,64 });
            v_speed.x += speed;
            if (clock.getElapsedTime().asSeconds() > 0.01f)
                v_speed.x = 0.f;
        }
        else if (keyDown(Key::W)) {
            clock.restart();
            people.setTextureRect(sf::IntRect{ 0,192,64,64 });
            v_speed.y -= speed;
            if (clock.getElapsedTime().asSeconds() > 0.01f)
                v_speed.y = 0.f;
        }
        else if (keyDown(Key::S)) {
            clock.restart();
            people.setTextureRect(sf::IntRect{ 0,0,64,64 });
            v_speed.y += speed;
            if (clock.getElapsedTime().asSeconds() > 0.01f)
                v_speed.y = 0.f;
        }

    }
    
    void Player::update(float dt)
    {
            auto w = people.getGlobalBounds().width;
            auto h = people.getGlobalBounds().height;
            people.move(v_speed );
            v_speed *= 0.f;
            //if player move out of bound
            
            //Left
            if (this->people.getGlobalBounds().left <= 0.f)
                this->people.setPosition(0.f, this->people.getGlobalBounds().top);
            //Right
            if (this->people.getGlobalBounds().left + this->people.getGlobalBounds().width >= 1260)
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

