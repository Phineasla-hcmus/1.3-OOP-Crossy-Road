#ifndef Player_h
#define Player_h

#include <SFML/Graphics.hpp>
#include "../Collidable.h"
#include <SFML/Audio.hpp>
#include "../../Framework/AssetManager/asset.h"

<<<<<<< Updated upstream
    /**
        Represents the player
    */
    class Player :public Collision
    {
    public:
        constexpr static int WIDTH = 44;
        constexpr static int HEIGHT = 32;
=======

/**
    Represents the player
*/
class Player :public Collision
{
public:
    constexpr static int WIDTH = 44;
    constexpr static int HEIGHT = 32;

    Player();
>>>>>>> Stashed changes

    void inputKeyPress();
    void update(float dt);
    void draw(sf::RenderTarget& target);           

    const sf::Vector2f& getPosition() const { return people.getPosition(); };
    void onCollide(Collision& other) override { is_Alive = false; }
     
<<<<<<< Updated upstream
        bool isAlive() const;

    private:
        void restart();

        sf::RectangleShape people;     
        sf::Vector2f v_speed;   
        sf::Vector2f origin_pos = { 640, 720 - 10 };
        float speed = 45.f;
        bool is_Alive = true;        

       
    };
=======
    bool isAlive() const; 
    void moving(); //moving if "walking" boolean is true
private:
    void restart();

    sf::RectangleShape people;     
    sf::Vector2f v_speed;   
    sf::Vector2f origin_pos = { 640, 720 - 90 };
    float speed = 45.f;
    bool is_Alive = true;        
    sf::Texture player_texture;
    
    float initX;
    float initY;
    float movespeed; //sets the movespeed
    
    enum MOVE { UP, DOWN, LEFT, RIGHT }; //enums instead of remember numbers
    bool move[4]; //deciding if u move up/down/left/right
    bool is_walking;
    int nextspot; //the next tilespot of the map
    
    sf::RectangleShape myrect;
};
>>>>>>> Stashed changes

#endif