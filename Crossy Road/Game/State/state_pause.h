#ifndef PAUSEMENU_H_
#define PAUSEMENU_H_
#include"Button.h"
#include"StackMenu.h"
#include"StateBase.h"
#include<SFML/Graphics.hpp>

class PauseMenu: public StateBase{
private:
	
	StackMenu pause_menu;
	bool is_paused = false;

public:
	PauseMenu(Game& game);
	
	void changeState();
	bool isPaused();
	void update(const sf::Vector2f& mousePos);
	void  draw(sf::RenderTarget& target);
	void handleEvent(sf::Event e) ;
	//void update(sf::Time deltaTime) ;
};

#endif // !PAUSEMENU_H_