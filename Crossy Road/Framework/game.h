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
class Game : public no_copy
{
private:
	struct save {
		unsigned level;
		unsigned score;
		struct road {
			float speed;
			int type;
		} roads[4];
		//std::array<road, 4> roads;
	} m_save;
	sf::Clock								dt_clock;
	sf::RenderWindow						m_window;
	std::stack<std::unique_ptr<state_base>> m_states;
	state_base& cur_state() const;
public:
	Game();
	//no_move
	Game(Game&&) = delete;
	void run();
	void pushState(std::unique_ptr<state_base> state);
	void popState();
	const sf::RenderWindow& get_window() const;
	sf::Time update_dt_clock();
};
#endif // !_main_game

