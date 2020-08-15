#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include <iostream>
#include "RigidBody.h"
#include "Collider.h"
#include "Player.h"
#include <time.h>
#include "Enemy.h"
#include "Spawner.h"
class Game
{
public:
	Game();
	virtual ~Game();
	void run();
	void Update();
	void Render();
	bool Collision();
private:
	bool GameOver;
	sf::RenderWindow* window;
	void initWindow();

	Player* player;
	void initPlayer();

	Enemy* enemy;
};

