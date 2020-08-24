#ifndef _state_playing
#define _state_playing
#include"../../Framework/State/state_base.h"
#include"../../Game/State/state_pause.h"
#include "../World.h"

class state_playing :public state_base {
private:
	World	m_world;
	int		m_score			= 0;
	bool	m_is_gameover	= false;
	bool    _is_paused      = false;
	int		m_level = 1;
	PauseMenu pause_menu;
public:
	state_playing(Game&);

	void handleEvent(sf::Event e)			override;
	void handleInput()                      override;
	void update(sf::Time delta_time)		override;	
	void draw(sf::RenderTarget& renderer)    override;
};
#endif // !_state_playing/
