#ifndef _state_playing
#include"../../Framework/State/state_base.h"
#include"../world.h"
class state_main_menu :public state_base {
private:
public:
	state_main_menu(Game&);

	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget& renderer)	override;
};
#endif // !_state_playing
