#ifndef _world_h
#define _world_h
#include <SFML/Graphics.hpp>

#include "../Entity/Player.h"
#include "../Entity//Road.h"
#include "../Entity/Vehicle.h"
constexpr auto x_tile = 16;
constexpr auto y_tile = 9;
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

private:

    Player m_player;



    std::vector<DRoad> m_road;
    std::vector<Vehicle*> m_vehicle;

    float vehicleSpawnTimer;
    float vehicleSpawnTimerMax;
    int maxVehicles;


    sf::RectangleShape _explodeShape;
    sf::Clock _invaderShotClock;
    sf::Clock _playerShotClock;
    sf::Clock _animalTimer;

   // sf::Sound m_playerShoot;
    

    bool _isGameOver = false;
};
#endif
