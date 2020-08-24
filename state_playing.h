#ifndef _state_playing
#define _state_playing
#include"PauseMenu.h"
#include "world.h"

class state_playing :public StateBase {
private:
	World	_world;
	int		_score			= 0;
	bool	_is_gameover	= false;
	bool    _is_paused      = false;
	PauseMenu pause_menu;
public:
	state_playing(Game&);

	void handleEvent(sf::Event e)			override;
	void handleInput()                      override;
	void update(sf::Time delta_time)		override;	
	void draw(sf::RenderTarget& renderer)   override;
};
#endif // !_state_playing/
