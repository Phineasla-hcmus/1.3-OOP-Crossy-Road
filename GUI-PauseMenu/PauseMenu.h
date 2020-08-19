#ifndef PAUSEMENU_H_
#define  PAUSEMENU_H_
#include<map>
#include"Button.h"
#include"StateBase.h"
#include"Game.h"
#include<SFML/Graphics.hpp>
class PauseMenu: public StateBase{
private:
	/*sf::Text menuText;
	sf::RectangleShape background;
	sf::RectangleShape container;
	std::map<std::string, Button*>buttions;*/
	StackMenu pause_menu;

public:
	PauseMenu(Game& game);
	//PauseMenu(const PauseMenu& b);
	//virtual ~PauseMenu();
	
	void update();
	void  render(sf::RenderTarget& target) override;
	
};

#endif // !PAUSEMENU_H_