#ifndef _state_playing
#include"../../Framework/State/state_base.h"
#include "../World.h"

class state_playing :public state_base {
private:
	World _world;
	int		_score			= 0;
	bool	_is_gameover	= false;
public:
	state_playing(game&);

	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget& renderer)	override;
};
#endif // !_state_playing
