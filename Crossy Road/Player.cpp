#include "Player.h"


void Player::keymove()
{
    /*keymove() and moving() functions are working together*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (walking == false)
        {
            /*if you click up, the the nextspot will of course be 50
            pixels above yourself, so thats why nextspot = y - tilsize*/
            nextspot = y - 50;
            /*this is gonna make sure you cant have move[UP] and move[LEFT]
            true on the same time so u wont walk 45 degrees*/
            move[UP] = true;
            walking = true;

        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (walking == false)
        {
            nextspot = y + 50;
            move[DOWN] = true;
            walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (walking == false)
        {
            nextspot = x - 50;
            move[LEFT] = true;
            walking = true;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (walking == false)
        {
            nextspot = x + 50;
            move[RIGHT] = true;
            walking = true;
        }
    }
}
void Player::moving()
{
    if (walking == true)
    {
        if (move[UP] == true)
        {
            y -= movespeed;

            /* i do <= and not just == because maybe your movespeed has a
            decimalpoint and then it wont become the same number as nextspot*/
            if (y <= nextspot)
            {
                y = nextspot;
                walking = false;
                move[UP] = false;
            }
        }

        if (move[DOWN] == true)
        {
            y += movespeed;
            if (y >= nextspot)
            {
                y = nextspot;
                walking = false;
                move[DOWN] = false;
            }
        }
        if (move[LEFT] == true)
        {
            x -= movespeed;
            if (x <= nextspot)
            {
                x = nextspot;
                walking = false;
                move[LEFT] = false;
            }
        }
        if (move[RIGHT] == true)
        {
            x += movespeed;
            if (x >= nextspot)
            {
                x = nextspot;
                walking = false;
                move[RIGHT] = false;
            }
        }
    }
}