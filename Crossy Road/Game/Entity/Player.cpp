#include "Player.h"
#include "../world.h"

static int initX = 0;
static int initY = 192;

int tilesize = 90;
Player::Player() :Collision(90.f, 64.f), move{ 0,0,0,0 }
{
    sf::Vector2f size_player = { 90.f,90.f };
    // in this case, every loop, it will walk 2 pixels. 
//if u put 50 as movespeed, it will walk 1 pixel each loop
    movespeed = 3.f;
    x = origin_pos.x, y = origin_pos.y;
    is_walking = false;


    people.setSize(size_player);
    people.setPosition(this->origin_pos);
   /* player_texture.loadFromFile("Assets\\textures\\player_sprite_2.png");*/
    player_texture = asset::texture().get("player_sprite_2", "png");
  
    people.setTexture(&player_texture);
    people.setTextureRect(sf::IntRect{ 0,192,64,64 });
}


void Player::keymove()
{
    /*keymove() and moving() functions are working together*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (is_walking == false)
        {
            nextspot = y - tilesize;
            move[UP] = true;
            is_walking = true;
            initY = 192;
            people.setTextureRect({ initX,initY,64,64 });
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (is_walking == false)
        {
            nextspot = y + tilesize;
            move[DOWN] = true;
            is_walking = true;
            initY = 0;
            people.setTextureRect({ initX,initY,64,64 });
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (is_walking == false)
        {
            nextspot = x - tilesize;
            move[LEFT] = true;
            is_walking = true;
            initY = 64;
            people.setTextureRect({ initX,initY,64,64 });
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (is_walking == false)
        {
            nextspot = x + tilesize;
            move[RIGHT] = true;
            is_walking = true;
            initY = 128;
            people.setTextureRect({ initX,initY,64,64 });
        }
    }
}
void Player::moving()
{
    if (is_walking == true)
    {
        if (move[UP] == true)
        {
            y -= movespeed;
            if (y <= nextspot)
            {
                y = nextspot;
                is_walking = false;
                move[UP] = false;
               
            }
        }

        if (move[DOWN] == true)
        {
            y += movespeed;
            if (y >= nextspot)
            {
                y = nextspot;
                is_walking = false;
                move[DOWN] = false;
            }
        }
        if (move[LEFT] == true)
        {
            x -= movespeed;
            if (x <= nextspot)
            {
                x = nextspot;
                is_walking = false;
                move[LEFT] = false;
            }
        }
        if (move[RIGHT] == true)
        {
            x += movespeed;
            if (x >= nextspot)
            {
                x = nextspot;
                is_walking = false;
                move[RIGHT] = false;
            }
        }
        people.setPosition(x, y);
    }
}
void Player::restart()
{
    /* v_speed *= 0.0f;*/
    /* people.setTextureRect(sf::IntRect{ 0,192,64,64 });*/
    is_Alive = true;
    people.setPosition(this->origin_pos);
}



void Player::update(float dt)
{

    //if player move out of bound

    //Left
    if (this->people.getGlobalBounds().left <= 10.f) 
        this->people.setPosition(10.f, this->people.getGlobalBounds().top);
    // 
    ////Right
    if (this->people.getGlobalBounds().left + this->people.getGlobalBounds().width >= 1270.f) 
        this->people.setPosition(1270 - this->people.getGlobalBounds().width, this->people.getGlobalBounds().top);
    //
    //Top
    if (this->people.getGlobalBounds().top <= -this->people.getGlobalBounds().height) {
        this->people.setPosition(this->people.getGlobalBounds().left, 720 - this->people.getGlobalBounds().height);
        y = origin_pos.y;
        World::levelUp();
        World::plusScore();
    }
    //Bottom
    if (this->people.getGlobalBounds().top + this->people.getGlobalBounds().height > 720) {
        this->people.setPosition(this->people.getGlobalBounds().left, 720 - this->people.getGlobalBounds().height);
        y = origin_pos.y;
    }

    //score 90,270,450,630    
    if (this->people.getGlobalBounds().top == 450) {
        World::plusScore();
        World::plus();
    }
    else if (this->people.getGlobalBounds().top == 270) {
        World::plusScore();
        World::plus();
    }
    else if (this->people.getGlobalBounds().top == 90) {
        World::plusScore();
        World::plus();
    }
    else World::n_plus();
        
    
    
}
void Player::animationRenderer() {
    if (m_clock.getElapsedTime().asSeconds() > m_gaps && is_walking == true) {
        if (initX > 192) {
            initX = 0;
            people.setTextureRect({ initX,initY,64,64 });
        }
        else {
            people.setTextureRect({ initX,initY,64,64 });
            initX += 64;
        }
        m_clock.restart();
    }
}

void Player::draw(sf::RenderTarget& target)
{
    sf::Clock clock;
    if (!is_Alive) {
        //people.setTextureRect(death_Animation.getFrame());
    }
    target.draw(people);
}




bool Player::isAlive() const
{
    return is_Alive;
}
