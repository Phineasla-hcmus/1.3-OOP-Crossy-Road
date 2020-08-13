#pragma once
#include "Crossy Road/Enemy.h"
#include <vector>


    class Spawner
    {
    public:
        Spawner();

        void drawEnemies(sf::RenderTarget& target);

       
        void initAddEnemy();
        bool areEnemiesActive() const;

    private:
    
        std::vector<Enemy> enemies;

        bool m_hasAllInvadersBeenAdded = false;

    };
