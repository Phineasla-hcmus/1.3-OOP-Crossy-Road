#include "Game.h"

#include "StateBase.h"
StateBase& Game::getCurrentState()
{
    return *m_states.back();
}
const sf::RenderWindow& Game::getWindow() const
{
    return window;
}
void Game::resizeWindow(unsigned width, unsigned height)
{
    window.close();
    window.create({ width, height }, "CROSSY ROAD");
}
Game::Game() : window({ 1280,720 }, "CROSSY ROAD") {
    window.setPosition({ window.getPosition().x,0 });
    window.setFramerateLimit(60);
    pushState<StateMainMenu>(*this);
}
void Game::run() {
    while (window.isOpen()) {
        auto& state = getCurrentState();
        //window.clear();
        state.render(window);
        window.display();
        handleEvent();
        tryPop();
    }
}
void Game::handleEvent()
{
    sf::Event e;

    while (window.pollEvent(e)) {
        getCurrentState().handleEvent(e);
        switch (e.type) {
        case sf::Event::Closed:
            window.close();
            break;

        default:
            break;

        }
    }
}
void Game::tryPop()
{
    if (m_shouldPop) {
        m_shouldPop = false;
        if (m_shouldExit) {
            m_states.clear();
            return;
        }
        else if (m_shouldChageState) {
            m_shouldChageState = false;
            m_states.pop_back();
            pushState(std::move(m_change));
            return;
        }

        m_states.pop_back();
        if (!m_states.empty()) {
            getCurrentState().onOpen();
        }
    }
}
void Game::pushState(std::unique_ptr<StateBase> state)
{
    m_states.push_back(std::move(state));
    getCurrentState().onOpen();
}
void Game::popState()
{
    m_shouldPop = true;
}

void Game::exitGame()
{
    m_shouldPop = true;
    m_shouldExit = true;
}