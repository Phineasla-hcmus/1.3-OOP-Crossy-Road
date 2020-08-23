#ifndef _state_base
#define _state_base
#include"SFML/Graphics.hpp"
#include"../Util/no_copy.h"
class Game;
class state_base : public no_copy
{
private:
	Game& m_game;
public:
	state_base(Game&);
	virtual ~state_base() = default;

	//virtual void handleInput();
	virtual void handleEvent(sf::Event) {};
	virtual void update		(sf::Time delta_time)	= 0;
	virtual void draw		(sf::RenderTarget&)		= 0;
	virtual void handleInput() {}
};
#endif // !_state_base

