#pragma once
#include <SFML\Graphics.hpp>
#include "Collidable.h"

class Player :public Collidable
{
private:

public:
    Player() :Collidable(50.f, 50.f)
    {
        x = 0;
        y = 0;
        m_location = sf::Vector2f(x, y);

        // in this case, every loop, it will walk 2 pixels. 
//if u put 50 as movespeed, it will walk 1 pixel each loop
        movespeed = 100.0 / 50;

        for (int i = 0; i < 4; ++i) //initialize the all move booleans to false
            move[i] = false;

        walking = false;
        myrect.setSize(sf::Vector2f(50, 50)); //size 50 by 50, same as every tile
    }


    void keymove(); //keypress detection
    void moving(); //moving if "walking" boolean is true

    float x;
    float y;
    float movespeed; //sets the movespeed

    enum MOVE { UP, DOWN, LEFT, RIGHT }; //enums instead of remember numbers
    bool move[4]; //deciding if u move up/down/left/right
    bool walking;
    int nextspot; //the next tilespot of the map
    bool m_isAlive;
    sf::Vector2f m_location;

    sf::RectangleShape myrect;
    void onCollide(Collidable& other) override {
        m_isAlive = false;
    }
    const sf::Vector2f& getPosition() const {
        return m_location;
    }
   
};
