#ifndef PAUSEMENU_H_
#define PAUSEMENU_H_
#include"../../Framework/GUI/Button.h"
#include"../../Framework/GUI/StackMenu.h"
#include"../../Framework/State/state_base.h"
#include<SFML/Graphics.hpp>
class PauseMenu: public state_base {
private:
	StackMenu pause_menu;
	bool is_paused = false;

public:
	PauseMenu(Game&);
	
	void changeState();
	bool isPaused();
	void  draw(sf::RenderTarget& target)    override;
	void handleEvent(sf::Event e)		   override ;
	void update(sf::Time dental_time)		override;
};

#endif // !PAUSEMENU_H_