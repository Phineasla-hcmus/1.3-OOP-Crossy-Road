#include "world.h"

world::world()
{
}

void world::draw(sf::RenderTarget& renderer)
{
	random rand;
	for (size_t i = 0; i < 20; ++i) {
		sf::RectangleShape shape(sf::Vector2f(rand.double_in_range(20, 50), rand.double_in_range(20, 50)));
		shape.setPosition(rand.int_in_range(0, 1280), rand.int_in_range(0, 800));
		shape.setFillColor(sf::Color::Green);
		renderer.draw(shape);
	}
}
