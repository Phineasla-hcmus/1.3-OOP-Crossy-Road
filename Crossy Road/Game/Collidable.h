#pragma once

#include <SFML/Graphics.hpp>


	class Collision
	{
	public:
		Collision() = default;
		Collision(const sf::Vector2f&);
		Collision(float width, float height);

		bool			tryCollideWith(Collision& other);
		virtual void	onCollide(Collision& other);
		virtual void	setSize(sf::Vector2f new_size);			//overwrite previous size
		virtual void	setSize(float width, float height);		//overwrite previous size

		virtual const sf::Vector2f& getPosition() const = 0;
		sf::FloatRect				getBox() const;

	private:
		sf::Vector2f m_size = { 0,0 };
	};
