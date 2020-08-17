#ifndef PAUSEMENU_H_
#define  PAUSEMENU_H_
#include<map>
#include"Button.h"
#include<SFML/Graphics.hpp>
class PauseMenu{
private:
	sf::Font& font;
	sf::Text menuText;
	sf::RectangleShape background, container;
	std::map<std::string, Button*>buttions;
public:
	PauseMenu(sf::RenderWindow& window,sf::Font& font);
	virtual ~PauseMenu();
	void update();
	void  render(sf::RenderTarget& target);

};

#endif // !PAUSEMENU_H_