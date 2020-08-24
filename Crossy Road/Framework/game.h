#ifndef _main_game
#define _main_game
#include<stack>
#include<vector>
#include<array>
#include<SFML/Graphics.hpp>
#include"State/state_base.h"
#include"Util/no_copy.h"
constexpr auto screen_width		= 1280;
constexpr auto screen_height	= 720;
constexpr auto num_lane			= 8;
constexpr auto tile_size		= screen_height / num_lane;
class Game : public no_copy
{
private:
	struct save {
		unsigned level;
		unsigned score;
		std::array<float, 4> speed_road;
		std::array<int, 4> obstacle_type_road;
	}					m_save;
	sf::Clock								m_dt_clock;
	sf::RenderWindow						m_window;
	std::stack<std::unique_ptr<state_base>> m_states;
	bool									m_pop_pending = false;
	bool									m_swap_pending = false;
	std::unique_ptr<state_base>				m_swap_state;//hold state for swapping
	state_base& cur_state() const;
	void pop();
	void swap();
	sf::Time update_dt_clock();
public:
	Game();
	//no_move
	Game(Game&&) = delete;
	void run();
	void pushState(std::unique_ptr<state_base>);
	//trigger bool var for pending pop/swap, prevent pop/swap too soon
	void popState();
	void swapState(std::unique_ptr<state_base> new_state);
	const sf::RenderWindow& get_window() const;
};
#endif // !_main_game

