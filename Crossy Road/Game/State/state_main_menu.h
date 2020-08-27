#ifndef _state_main_menu
#define _state_main_menu
#include"state_load.h"
#include"../../Framework/GUI/button.h"
#include"../../Framework/GUI/StackMenu.h"
#include"../../Framework/AssetManager/asset.h"
#include"../State/state_playing.h"
class state_main_menu :public state_base {
private:
	sf::RectangleShape m_container;
	StackMenu m_mainMenu;
	sf::RectangleShape m_banner;
public:
	state_main_menu(Game&);

	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget& renderer)	override;
};
#endif // !_state_playing
