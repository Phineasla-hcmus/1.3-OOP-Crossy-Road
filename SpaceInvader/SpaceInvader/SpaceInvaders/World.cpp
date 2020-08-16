#include "World.h"
#include "../Framework/ResourceManager/ResourceHolder.h"
#include <time.h>

namespace CrossRoad
{
    World::World()
        : m_projectileRenderer(4, 8, Projectile::WIDTH, Projectile::HEIGHT,
            ResourceHolder::get().textures.get("si/projectile"))
        , m_ufo(m_rng)
        , m_invaders(*this)
    {
        /* m_explodeShape.setSize({ 52, 28 });
        m_explodeShape.setTexture(&ResourceHolder::get().textures.get("si/explosion"));

        const int SECT_SIZE = (Display::WIDTH / 4);
        for (int i = 0; i < 4; i++) {

            m_shields.emplace_back(float(i * SECT_SIZE + SECT_SIZE / 2 - Shield::SIZE / 2));
        }

        m_playerShoot.setBuffer(ResourceHolder::get().soundBuffers.get("si/shoot"));
        m_playerShoot.setVolume(25);*/

        //init road
        float old = 0;
        for (int i = 0; i < 4; ++i) {
            sf::Vector2f pos;
            pos.x = 0;
            pos.y =old;            
            m_road.push_back(pos);            
            old = pos.y + m_road[0].getDistance();
        }

        
        
    }

    void World::input()
    {
        if (m_player.isAlive()) {
            if (m_invaders.areInvadersAlive()) {
                m_player.inputKeyPress();
                //playerProjectileInput();
            }
        }
        else {
           // m_player.tryRevive();
        }
    }

    int World::update(float dt)
    {
        int score = 0;
        for (auto& road : this->m_road)
            road.update();

        m_player.update(dt);
        if (m_invaders.areInvadersAlive()) {
            
            
         
        }
        else {
            m_invaders.initAddInvader();
            
        }
        return score;
    }

    const Player & World::getPlayer() const
    {
        return m_player;
    }

    bool World::isGameOver() const
    {
        return 
            //m_player.getLives() == -1 || 
            m_isGameOver;
    }

    //TODO GENERALISE THESE TWO FUNCTIONS VV
    void World::playerProjectileInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
            m_playerShotClock.getElapsedTime().asSeconds() > 0.5f) {
            //auto point = m_player.getGunPosition();
           // point.y -= Projectile::HEIGHT;
           // point.x -= Projectile::WIDTH / 2.0f;
            //m_projectiles.emplace_back(point, Projectile::Type::Rectangle, Projectile::Direction::Up);
            m_playerShotClock.restart();
            m_playerShoot.play();
        }
    }

    void World::enemyProjectileFire()
    {
        if (m_invaderShotClock.getElapsedTime().asSeconds() >= 0.1 &&
            m_rng.getIntInRange(0, 30) == 2) {
            auto point = m_invaders.getRandomLowestInvaderPoint(m_rng);
            if ((int)point.x == -1) return;
            auto type = static_cast<Projectile::Type>(m_rng.getIntInRange(1, 2));
            m_projectiles.emplace_back(point, type, Projectile::Direction::Down);
            m_invaderShotClock.restart();
        }
    }
    //end of to-do

    /*
    CollisionResult World::getCollisionResult(float dt)
    {
        auto result = m_invaders.tryCollideWithProjectiles(m_projectiles);
        updateProjectiles(dt, result.second);

        for (auto& projectile : m_projectiles) {

            //Projectile verses sheild collisons
            for (auto& sheild : m_shields) {
                if (sheild.isTouching(projectile)) {
                    projectile.destroy();
                    result.second.emplace_back(projectile.getPosition());
                }
            }

            //Projectile verses UFO collisons
            if (m_ufo.tryCollideWith(projectile)) {
                result.second.emplace_back(projectile.getPosition());
                result.first += 200;
            }

            //Projectile verses projectile collisions
            for (auto& otherProjectile : m_projectiles) {
                if (otherProjectile.getID() != projectile.getID()) {
                    if (otherProjectile.tryCollideWith(projectile)) {
                        result.second.emplace_back(projectile.getPosition());
                    }
                }
            }
        }


        return result;
    }

    */


    void World::updateProjectiles(float dt, std::vector<sf::Vector2f>& collisionPoints)
    {
        for (auto itr = m_projectiles.begin(); itr != m_projectiles.end();) {
            auto& projectile = *itr;
            if (!projectile.isActive()) {
                itr = m_projectiles.erase(itr);
            }
            else {
                //Test for player getting hit 
                if (projectile.tryCollideWith(m_player)) {
                    //collisionPoints.emplace_back(m_player.getGunPosition());
                    m_projectiles.clear();
                    return;
                }
                projectile.update(dt);
                itr++;
            }
        }
    }

    void World::draw(sf::RenderTarget & target)
    {
        
        for (auto& droad : m_road) {
            droad.draw(target);
        }
        m_player.draw(target);
      
        
    }
}//Namespace SpaceInvaders