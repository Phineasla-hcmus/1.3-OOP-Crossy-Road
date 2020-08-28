#ifndef _state_main_menu
#define _state_main_menu
//#include"../../Framework/State/state_base.h"
//#include"../../Framework/GUI/button.h"
//#include"../../Framework/GUI/StackMenu.h"
//#include"../../Framework/AssetManager/asset.h"
#include "../../PCH.h"
#include "../Background.h"
constexpr auto BACKGROUND_MUSIC_DIR = "Assets/audio/music.ogg";
class state_main_menu :public state_base {
private:
	sf::RectangleShape	m_container;
	sf::RectangleShape	m_banner;
	Background			m_background;
	StackMenu			m_mainMenu;
	sf::Music			m_music;
	void				open_music(const std::string & = BACKGROUND_MUSIC_DIR);
public:
	state_main_menu(Game&);

	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget&)			override;
};
#endif // !_state_playing
