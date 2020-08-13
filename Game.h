#ifndef _GAME_H_
#define _GAME_H_
#include"SFML\Graphics.hpp"
#include<memory>
#include<vector>
#include"StateBase.h"
#include"StateMainMenu.h"
class Game {
private:
    sf::RenderWindow window;
    StateBase& getCurrentState();
    std::vector<std::unique_ptr<StateBase>> m_states;
    void handleEvent();
    void tryPop();
    bool m_shouldPop = false;
    bool m_shouldExit = false;
    bool m_shouldChageState = false;
    std::unique_ptr<StateBase> m_change;
public:

    void popState();
    void exitGame();
    Game();
    void run();
    const sf::RenderWindow& getWindow() const;
    void resizeWindow(unsigned width, unsigned height);
    template<typename T, typename... Args>
    void pushState(Args&&... args);
    void pushState(std::unique_ptr<StateBase> state);
    template<typename T, typename... Args>
    void changeState(Args&&... args);
};
template<typename T, typename... Args>
inline void Game::pushState(Args&&... args)
{
    pushState(std::make_unique<T>(std::forward<Args>(args)...));
}
template<typename T, typename ...Args>
inline void Game::changeState(Args&& ...args)
{
    m_change = std::make_unique<T>(std::forward<Args>(args)...);
    m_shouldPop = true;
    m_shouldChageState = true;
}

#endif // !_GAME_H_