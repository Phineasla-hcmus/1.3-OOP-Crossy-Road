#ifndef _state_base
#define _state_base
#include"SFML/Graphics.hpp"
#include"../Util/no_copy.h"
class game;
class state_base : public no_copy
{
private:
	game& _game;
public:
	state_base(game&);
	virtual ~state_base() = default;

	virtual void handleEvent(sf::Event e)			= 0;
	virtual void handleInput()						= 0;
	virtual void update(sf::Time delta_time)		= 0;
	virtual void render(sf::RenderTarget& renderer) = 0;
};
#endif // !_state_base

