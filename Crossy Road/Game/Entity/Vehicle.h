#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Player.h"

	
	class Vehicle {
	protected:
		sf::RectangleShape vehicle;
		friend class DRoad;
	public:
		Vehicle(sf::Color color = sf::Color::White, sf::Vector2f position = { 0.f,0.f }, sf::Vector2f size = { 1.f,1.f });

		virtual const sf::Vector2f& getPosition()const = 0;
		virtual void draw(sf::RenderTarget& target) = 0;
	};

	class Car :public Vehicle {
	private:

	public:
		Car(sf::Vector2f position = { 0.f,0.f });
		void draw(sf::RenderTarget& target);
		const sf::Vector2f& getPosition()const { return vehicle.getPosition(); };
	};

	class Bike :public Vehicle {
	private:
	public:
		Bike(sf::Vector2f position = { 0.f,0.f }) ;

		void draw(sf::RenderTarget& target);
		const sf::Vector2f& getPosition() const {
			return vehicle.getPosition();
		};
	};


	

