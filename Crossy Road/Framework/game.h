#ifndef _main_game
#define _main_game
#include<stack>
#include<vector>
#include<SFML/Graphics.hpp>
#include"State/state_base.h"
#include"Util/no_copy.h"
constexpr auto screen_width		= 1280;
constexpr auto screen_height	= 720;
constexpr auto num_lane			= 8;
constexpr auto tile_size		= screen_height / num_lane;
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
	const sf::RenderWindow& get_window() const;
	sf::Time update_dt_clock();
};
#endif // !_main_game

