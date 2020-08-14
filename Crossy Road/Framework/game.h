#ifndef _main_game
#define _main_game
#include<stack>
#include<vector>
#include<SFML/Graphics.hpp>
#include"State/state_base.h"
#include"Util/no_copy.h"
class game : public no_copy
{
private:
	sf::Clock								dt_clock;
	sf::RenderWindow						_window;
	std::stack<std::unique_ptr<state_base>> _states;
	state_base& cur_state() const;
public:
	game();
	//no_move
	game(game&&) = delete;
	void run();
	void pushState(std::unique_ptr<state_base> state);
	void popState();
	sf::Time update_dt_clock();
};
#endif // !_main_game

