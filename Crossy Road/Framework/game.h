#ifndef _main_game
#define _main_game
#include<stack>
#include<vector>
#include<array>
#include<SFML/Graphics.hpp>
#include"Util/io_config.h"
#include"Util/no_copy.h"
#include"State/state_base.h"
constexpr auto SCREEN_WIDTH		= 1280;
constexpr auto SCREEN_HEIGHT	= 720;
constexpr auto x_tiles			= 14;
constexpr auto y_tiles			= 8;
constexpr auto tile_size		= SCREEN_HEIGHT / y_tiles;
class Game : public no_copy
{
private:
	sf::Clock								m_dt_clock;
	sf::RenderWindow						m_window;
	std::stack<std::unique_ptr<state_base>> m_states;
	bool									m_pop_pending = false;
	bool									m_swap_pending = false;
	std::unique_ptr<state_base>				m_swap_state;//hold state for swapping
	textureLookup							m_vehicles_set;
	
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

	size_t getStateSize() const;
	const sf::RenderWindow& get_window() const;
	const textureLookup& get_texture_set() const;
};
#endif // !_main_game

