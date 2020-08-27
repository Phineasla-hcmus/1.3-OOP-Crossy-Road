#pragma once

#include <SFML/Graphics.hpp>


	class Collision
	{
	public:
		Collision() = default;
		Collision(const sf::Vector2f&);
		Collision(float width, float height);

		bool			tryCollideWith(Collision& other);
		//overwrite previous size
		void			setSize(sf::Vector2f new_size);
		sf::FloatRect	getBox() const;

		virtual const sf::Vector2f& getPosition() const = 0;
		virtual void onCollide(Collision& other);

	private:
		sf::Vector2f m_size = { 0,0 };
	};
