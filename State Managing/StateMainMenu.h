#ifndef _STATEMAINMENU_H_
#define  _STATEMAINMENU_H_
#include"StateBase.h"
#include"StackMenu.h"

namespace Display
{
    constexpr unsigned WIDTH = 1000;
    constexpr unsigned HEIGHT = 800;
}

class StateMainMenu : public StateBase {
public:
    StateMainMenu(Game& game);
    void handleEvent(sf::Event e)   override;
    // void handleInput() override {};
    void render(sf::RenderTarget& renderer);
    void setPosition(const sf::Vector2f position);
    void draw(sf::RenderTarget& renderer);
private:

    sf::RectangleShape m_container;
    sf::RectangleShape m_thumbnail;
    StackMenu m_mainMenu;
    sf::RectangleShape m_banner;
    //StarryBackground m_background;

};

#endif // !1