#ifndef PAUSEMENU_H_
#define PAUSEMENU_H_

#include "../../PCH.h"
#include"../SaveLevel.h"
class PauseMenu: public state_base {
private:
	StackMenu m_menu;
	bool m_isPaused = false;
	SaveInf m_save;
public:
	PauseMenu(Game&);
	
	void changeState();
	bool isPaused();
	void draw(sf::RenderTarget& target)		override;
	void handleEvent(sf::Event e)			override;
	void update(sf::Time dental_time)		override;
	void updateSaveInfo(SaveInf& save);
};


#endif // !PAUSEMENU_H_