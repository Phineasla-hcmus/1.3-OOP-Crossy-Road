#ifndef _world_h
#define _world_h
#include <SFML/Graphics.hpp>

#include "Entity/Player.h"
#include "Entity/Road.h"
#include "Entity/Vehicle.h"

constexpr auto x_tile = 14;
constexpr auto y_tile = 8;
/*
    Manages the world and interactions between different entites
*/
class World 
{
public:
    World();

    void input();
    int update(float dt);
    void draw(sf::RenderTarget& target);
    const Player& getPlayer() const;
    bool isGameOver() const;
    void setGameIsOver() { _isGameOver = true; }
    void resetRoad();
    int getLevel()const;
    static void levelUp();
private:

    Player _people;

    std::vector<DRoad> m_road;
    std::vector<Vehicle*> m_vehicle;
    
    int maxVehicles;
    static int level;
    float base_vehicle_speed = 30;
    float step_vehicle_speed = 0;

    bool _isGameOver = false;
};
#endif
