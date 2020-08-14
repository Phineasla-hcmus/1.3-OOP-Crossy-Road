#ifndef _STATEBASE_H_
#define _STATEBASE_H_
#include<SFML\Graphics.hpp>
class Game;
class StateBase
{
protected:
    std::string m_name;
    Game* m_pGame;
public:
    StateBase(Game& game, const char* name);
    StateBase(Game& game, const char* name, unsigned resizeWindowWidth, unsigned resizeWindowHeight);
    virtual ~StateBase() = default;
    virtual void onOpen() {}
    virtual void handleEvent(sf::Event e) {}
    virtual void handleInput() {}
    virtual void update(sf::Time deltaTime) {}
    virtual void fixedUpdate(sf::Time deltaTime) {}
    virtual void render(sf::RenderTarget& renderer) {}
    const std::string& getName() { return m_name; }
};

#endif // !_STATEBASE_H_