#include "game.h"
void Game::handleEvent()
{
    sf::Event e;

    while (m_window.pollEvent(e)) {
        switch (e.type) {
        case sf::Event::Closed:
            m_window.close();
            break;

        default:
            break;

        }
    }
}
void Game::Draw(sf::RenderTarget& target)
{
    spawner.drawEnemies(target); 
}
Game::Game()
    : m_window({ 1280, 720 }, "Hopson Arcade")
{
    m_window.setPosition({ m_window.getPosition().x, 0 });
    m_window.setFramerateLimit(60);
    obj.setSize(sf::Vector2f(50.f, 50.f));
    obj.setFillColor(sf::Color::Green);

    sf::Image icon;
    //icon.loadFromFile("D:/GitHub/SpaceInvader/res/txrs/icon.ico");
    //m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
void Game::run() {
    constexpr unsigned TPS = 30; //ticks per seconds
    const sf::Time     timePerUpdate = sf::seconds(1.0f / float(TPS));
    unsigned ticks = 0;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag = sf::Time::Zero;

    //Main loop of the game
    while (m_window.isOpen()) {



        //Render
        m_window.clear();
   
       /* spawner.initAddObject();*/
        m_window.draw(obj);
        m_window.display();


        //Handle window events
        handleEvent();
        /*tryPop();*/
    }

}