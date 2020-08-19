#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Player.h"


	
	class Vehicle {
	protected:
		sf::RectangleShape vehicle;
		friend class DRoad;
	public:
		Vehicle(sf::Color color = sf::Color::White, sf::Vector2f position = { 0.f,0.f }, sf::Vector2f size = { 1.f,1.f });


		virtual void draw(sf::RenderTarget& target) = 0;
	};

	class Car :public Vehicle {
	private:

	public:
		Car(sf::Vector2f position = { 0.f,0.f });
		void draw(sf::RenderTarget& target);

	};

	class Bike :public Vehicle {
	private:
	public:
		Bike(sf::Vector2f position = { 0.f,0.f }) ;

		void draw(sf::RenderTarget& target);

	};


	

