#include "Player.h"
#include "../world.h"
<<<<<<< Updated upstream
#include<iostream>
    Player::Player() :Collision(90.f,90.f)
    {
        sf::Vector2f size_player = { 90.f,90.f };
        people.setSize(size_player);        
        people.setPosition(this->origin_pos);
       // people.setTextureRect({ 0, 0, 11, 8 });
        
=======

int tilesize = 50;
static int x = 0;
static int y = 0;

Player::Player() :Collision(90.f, 90.f), move{ 0,0,0,0 },is_walking(0)
{
    sf::Vector2f size_player = { 90.f,90.f };
    people.setPosition(this->origin_pos);
    people.setSize(size_player);
  //  player_texture.loadFromFile("Assets\\textures\\player_sprite_2.png");
  ///*  people.setTexture(&asset::texture().get("player_sprite_2.png", "Can't load png"));*/
  //  people.setTexture(&player_texture);
  //  people.setTextureRect(sf::IntRect{ 0,192,64,64 });
    initX = 640, initY = 720-90;
    
    // in this case, every loop, it will walk 2 pixels. 
    //if u put 50 as movespeed, it will walk 1 pixel each loop
    movespeed = 10.f;
    //for (int i = 0; i < 4; ++i) //initialize the all move booleans to false
    //    move[i] = false;
    //
    myrect.setSize(sf::Vector2f(90.f, 90.f)); //size 50 by 50, same as every tile
}
void Player::inputKeyPress()
{
    /*keymove() and moving() functions are working together*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (is_walking == false)
        {
            /*if you click up, the the nextspot will of course be 50
            pixels above yourself, so thats why nextspot = y - tilsize*/
            nextspot = initY - 90.f;
            /*this is gonna make sure you cant have move[UP] and move[LEFT]
            true on the same time so u wont walk 45 degrees*/
            move[UP] = true;
            is_walking = true;

        }
>>>>>>> Stashed changes
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
<<<<<<< Updated upstream
        v_speed *= 0.0f;
      //  people.setTextureRect({ 0, 0, 11, 8 });//
        is_Alive = true;        
        people.setPosition(this->origin_pos);
=======
        if (is_walking == false)
        {
            nextspot = initY + 90.f;
            move[DOWN] = true;
            is_walking = true;
        }
>>>>>>> Stashed changes
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
<<<<<<< Updated upstream
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
=======
        if (is_walking == false)
        {
            nextspot = initX - 90.f;
            move[LEFT] = true;
            is_walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (is_walking == false)
        {
            nextspot = initX + 90.f;
            move[RIGHT] = true;
            is_walking = true;
        }
    }
}
void Player::restart()
{
  
    people.setTextureRect(sf::IntRect{ 0,192,64,64 });
    is_Alive = true;        
    people.setPosition(this->origin_pos);
}
 

void Player::moving()
{
    if (is_walking == true)
    {
     
        if (move[UP] == true)
        {
            initY -= movespeed;

            /* i do <= and not just == because maybe your movespeed has a
            decimalpoint and then it wont become the same number as nextspot*/
            if (initY <= nextspot)
            {
                initY = nextspot;
                is_walking = false;
                move[UP] = false;
            }
        }

        if (move[DOWN] == true)
        {
            initY += movespeed;
            if (initY >= nextspot)
            {
                initY = nextspot;
                is_walking = false;
                move[DOWN] = false;
            }
        }
        if (move[LEFT] == true)
        {
            initX -= movespeed;
            if (initX <= nextspot)
            {
                initX = nextspot;
                is_walking = false;
                move[LEFT] = false;
            }
        }
        if (move[RIGHT] == true)
        {
            initX += movespeed;
            if (initX >= nextspot)
            {
                initX = nextspot;
                is_walking = false;
                move[RIGHT] = false;
            }
        }
        people.setPosition(initX, initY);
    }
  
}
//void Player::inputKeyPress()
//{
//
//    using Key = sf::Keyboard::Key;
//    auto keyDown = [](sf::Keyboard::Key k) {
//        return sf::Keyboard::isKeyPressed(k);
//    };
//    sf::Clock clock;
//    if (keyDown(Key::A)) {
//        clock.restart();
//        v_speed.x -= speed;
//        y = 64;
//        if (clock.getElapsedTime().asSeconds() > 0.01f)
//            v_speed.x = 0.f;
//    }
//    else if (keyDown(Key::D)) {
//        clock.restart();
//        y = 128;
//        v_speed.x += speed;
//        if (clock.getElapsedTime().asSeconds() > 0.01f)
//            v_speed.x = 0.f;
//    }
//    else if (keyDown(Key::W)) {
//        y = 192;
//        clock.restart();
//        v_speed.y -= speed;
//        if (clock.getElapsedTime().asSeconds() > 0.01f)
//            v_speed.y = 0.f;
//    }
//    else if (keyDown(Key::S)) {
//        y = 0;
//        clock.restart();
//        v_speed.y += speed;
//        if (clock.getElapsedTime().asSeconds() > 0.01f)
//            v_speed.y = 0.f;
//    }
//
//}
    
>>>>>>> Stashed changes
    void Player::update(float dt)
    {
        if (is_Alive) {
            auto w = people.getGlobalBounds().width;
            auto h = people.getGlobalBounds().height;
<<<<<<< Updated upstream
            people.move(v_speed);
     
            v_speed *= 0.f;
=======
           
          
>>>>>>> Stashed changes
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
             /*   World::levelUp();*/
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
<<<<<<< Updated upstream
        else
            target.draw(people);
        
=======
        else {
          /*  if (x == 192) {
                x = 0;
            }
            else {
                this->people.setTextureRect(sf::IntRect{ x,y,64,64 });
                x += 64;*/
                target.draw(people);
          /*  }*/  
        }
>>>>>>> Stashed changes
    }

   


    bool Player::isAlive() const
    {
        return is_Alive;
    }   

