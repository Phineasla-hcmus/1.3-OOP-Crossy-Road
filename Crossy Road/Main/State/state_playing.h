#ifndef _state_playing
#include"../../Framework/State/state_base.h"
class state_playing :public state_base {
private:
	int		_score			= 0;
	bool	_is_gameover	= false;
public:
	state_playing(game&);

	virtual void handleEvent(sf::Event e)			override;
	virtual void update(sf::Time delta_time)		override;
	virtual void render(sf::RenderTarget& renderer)	override;
};
#endif // !_state_playing
