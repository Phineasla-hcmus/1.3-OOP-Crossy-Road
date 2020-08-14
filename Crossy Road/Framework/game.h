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
	sf::Clock dt_clock;
	std::stack<std::unique_ptr<state_base>> _states;
	state_base& cur_state() const;
public:
	game(const game&)	= delete;
	game(game&&)		= delete;
	game();
	void run();
	void update_dt_clock();
};
#endif // !_main_game

