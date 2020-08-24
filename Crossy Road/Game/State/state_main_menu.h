#ifndef _state_playing
#define _state_playing
#include"../../Framework/GUI/button.h"
#include"../../Framework/GUI/StackMenu.h"
#include"../../Framework/AssetManager/asset.h"
#include"../../Framework/game.h"
class state_main_menu :public state_base {
private:
	sf::RectangleShape m_container;
	sf::RectangleShape m_thumbnail;
	StackMenu m_mainMenu;
	sf::RectangleShape m_banner;
public:
	state_main_menu(Game&);

	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget& renderer)	override;
};
#endif // !_state_playing
