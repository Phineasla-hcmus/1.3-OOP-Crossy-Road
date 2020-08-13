#ifndef _state_base
#define _state_base
#include"SFML/Graphics.hpp"
class state_base
{
private:

public:
	state_base();
	virtual ~state_base();

	virtual void update(sf::Time delta_time) = 0;
	virtual void render() = 0;

};
#endif // !_state_base

