#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.h"

class Spawner
{
public:
	Spawner();
	~Spawner();
	void Update(RenderWindow& window, RectangleShape body);
private:
	void initEnemies();
	vector<Enemy*>enemies;
	float spawnTimer;
	float spawnTimerMax;
};

