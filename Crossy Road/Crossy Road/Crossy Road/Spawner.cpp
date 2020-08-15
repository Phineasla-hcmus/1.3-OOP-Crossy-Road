#include "Spawner.h"
void Spawner::initEnemies() {
	this->spawnTimerMax = 100.0f;
	this->spawnTimer = this->spawnTimerMax;
}
Spawner::Spawner() {
	this->initEnemies();
}
Spawner::~Spawner() {}
void Spawner::Update(RenderWindow &window,RectangleShape body) {
	int i = 0;
	spawnTimer += 10.f;
	if (this->spawnTimer >= spawnTimerMax) {
		cout << "New enemy!" << endl;
		this->enemies.push_back(new Enemy(100.f, 100.f, window));
	
		i++;
		spawnTimer = 0.f;
	}
	for (int i = 0; i < this->enemies.size(); i++) {
		enemies[i]->Update(window);
		if (this->enemies[i]->getBounds().left > 600) {
			cout << "Delete enemy!!" << endl;
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}