#ifndef _STATEBASE_H_
#define _STATEBASE_H_
#include<SFML\Graphics.hpp>
class Game;
class StateBase
{
protected:
    Game* m_pGame;
public:
    StateBase(Game& game);
    virtual ~StateBase() = default;
    virtual void handleEvent(sf::Event e) {}
    virtual void update(sf::Time deltaTime) {}
    virtual void render(sf::RenderTarget& renderer) {}
    //virtual void handleInput();
};

#endif // !_STATEBASE_H_