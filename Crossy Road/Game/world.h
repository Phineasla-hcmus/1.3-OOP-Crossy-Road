#pragma once

#include <SFML/Graphics.hpp>

#include "../Entity/Player.h"
#include "../Entity//Road.h"
#include "../Entity/Vehicle.h"


    /**
        The class which manages the world and th interactions between different entites
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

    void setGameIsOver() { m_isGameOver = true; }

private:

    Player m_player;



    std::vector<DRoad> m_road;
    std::vector<Vehicle*> m_vehicle;

    float vehicleSpawnTimer;
    float vehicleSpawnTimerMax;
    int maxVehicles;


    sf::RectangleShape m_explodeShape;
    sf::Clock m_invaderShotClock;
    sf::Clock m_playerShotClock;
    sf::Clock m_animTimer;

    sf::Sound m_playerShoot;
    

    bool m_isGameOver = false;
};
