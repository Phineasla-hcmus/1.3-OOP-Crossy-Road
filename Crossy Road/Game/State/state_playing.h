#ifndef _state_playing
#define _state_playing

#include "../../PCH.h"
#include "../World.h"
#include "state_pause.h"
class state_playing :public state_base {
private:
	SaveInf		m_save;
	World		m_world;
	int			m_score			= 0;
	bool		m_is_gameover	= false;
	bool		m_is_paused     = false;
	int			m_level			= 1;
	PauseMenu	m_pause_menu;
public:
	state_playing(Game&);//start at level 1
	state_playing(Game&, const SaveInf&);//call in state_load

	void handleEvent(sf::Event e)			override;
	void handleInput()                      override;
	void update(sf::Time delta_time)		override;	
	void draw(sf::RenderTarget& renderer)    override;
};
#endif // !_state_playing/
