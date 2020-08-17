#ifndef _GAME_H_
#define _GAME_H_
#include"SFML\Graphics.hpp"
#include<memory>
#include<vector>
#include<stack>
#include"StateBase.h"
#include"StateMainMenu.h"
class Game {
private:
    sf::RenderWindow window;
    StateBase& cur_state() const;
    std::stack<std::unique_ptr<StateBase>> m_states;
    sf::Clock dt_clock;
   
public:
    Game(Game&&) = delete;
    Game();
    void run();
    void pushState(std::unique_ptr<StateBase> state);
    sf::Time update_dt_clock();
    const sf::RenderWindow& getWindow() const;
    template<typename T, typename Args>
    inline void pushState(Args&& args);
    bool exit = false;
};
template<typename T, typename Args>
inline void Game::pushState(Args&& args)
{
    pushState(std::make_unique<T>(std::forward<Args>(args)));
}
#endif // !_GAME_H_