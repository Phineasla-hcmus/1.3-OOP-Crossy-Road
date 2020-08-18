#ifndef _main_game
#define _main_game
#include<stack>
#include<vector>
#include<SFML/Graphics.hpp>
#include "Enemy.h"
#include "Spawner.h"

class Game
{
private:
    void handleEvent();
    /*void tryPop();*/
    Spawner spawner;
    Object obj;
    Object obj2;
    sf::RenderWindow m_window;

public:
    void Draw(sf::RenderTarget& target);
    Game();
    void run();
};
#endif // !_main_game
