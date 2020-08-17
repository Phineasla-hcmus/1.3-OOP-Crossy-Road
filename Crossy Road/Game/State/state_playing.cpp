#include "state_playing.h"

state_playing::state_playing(game& game)
	: state_base(game)
	, _world()
{

}

void state_playing::handleEvent(sf::Event ev)
{
}

void state_playing::update(sf::Time delta_time)
{
}

void state_playing::draw(sf::RenderTarget& render)
{
	_world.draw(render);
}
