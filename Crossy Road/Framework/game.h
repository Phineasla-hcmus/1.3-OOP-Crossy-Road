#ifndef _main_game
#define _main_game
#include<stack>
#include<vector>
#include<SFML/Graphics.hpp>
#include"State/state_base.h"

class game
{
private:
	sf::RenderWindow _window;
	std::stack<std::unique_ptr<state_base>> _states;
public:
	game(const game&)	= delete;
	game(game&&)		= delete;
	game();
	void run();
};
#endif // !_main_game

