#include "Player.h"
#include "../world.h"

Player::Player() :Collision(90.f,90.f)
{
    sf::Vector2f size_player = { 90.f,90.f };
    m_player.setSize(size_player);        
    m_player.setPosition(this->origin_pos);
    // people.setTextureRect({ 0, 0, 11, 8 });
        
}

void Player::restart()
{
    v_speed *= 0.0f;
    //  people.setTextureRect({ 0, 0, 11, 8 });//
    is_Alive = true;        
    m_player.setPosition(this->origin_pos);
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
        auto w = m_player.getGlobalBounds().width;
        auto h = m_player.getGlobalBounds().height;
        m_player.move(v_speed );
        v_speed *= 0.f;
        //if player move out of bound
            
        //Left
        if (this->m_player.getGlobalBounds().left <= 0.f)
            this->m_player.setPosition(0.f, this->m_player.getGlobalBounds().top);
        //Right
        if (this->m_player.getGlobalBounds().left + this->m_player.getGlobalBounds().width >= 1280)
            this->m_player.setPosition(1280- this->m_player.getGlobalBounds().width, this->m_player.getGlobalBounds().top);
        //Top
        if (this->m_player.getGlobalBounds().top <= 0.f) {
            this->m_player.setPosition(this->m_player.getGlobalBounds().left, 720 - this->m_player.getGlobalBounds().height);
            World::levelUp();
        }
        //Bottom
        if (this->m_player.getGlobalBounds().top + this->m_player.getGlobalBounds().height >= 720)
            this->m_player.setPosition(this->m_player.getGlobalBounds().left, 720 - this->m_player.getGlobalBounds().height);
    }
}

void Player::draw(sf::RenderTarget& target)
{
    if (!is_Alive) {
        //people.setTextureRect(death_Animation.getFrame());
    }
    else
        target.draw(m_player);
        
}

  
bool Player::isAlive() const
{
    return is_Alive;
}   

