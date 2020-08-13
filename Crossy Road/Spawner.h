#pragma once
#include "Crossy Road/Enemy.h"
#include <vector>


namespace SpaceInvaders
{
    class World;

    using CollisionResult = std::pair<int, std::vector<sf::Vector2f>>;

    /**
        Class to manage the drawing and updating of invaders
    */
    class Spawner
    {
    public:
        Spawner(World& world);

        void drawEnemies(sf::RenderTarget& target);

       
        void initAddEnemy();
        bool areEnemiesActive() const;

    private:
    
        std::vector<Enemy> enemies;
        World& m_world;

        bool m_hasAllInvadersBeenAdded = false;

    };
}