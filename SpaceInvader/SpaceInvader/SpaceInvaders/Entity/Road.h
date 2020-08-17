#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Vehicle.h"

namespace CrossRoad {
	

	class DRoad {
	private:
		sf::RectangleShape lane;
		float width;
		float distance;
		std::vector<Vehicle*> r_vehicle;
		float vehicleSpawnTimer;
		float vehicleSpawnTimerMax;
		int maxVehicle;
		float speed;
		int isFromLeft;

	public:
		DRoad(sf::Vector2f pos = { 0.f,0.f }, float speed = 0.0001, int isFromLeft = 1);
		void initVehicle();
		void initVar(float width = 90, float distance = 90);
		void initShape(sf::Vector2f position = { 0,0 });
		float getDistance();
		void update(float dt);
		void draw(sf::RenderTarget& target);
		sf::Vector2f getCenterRoadPosition();
		void spawnVehicle();
	};
}