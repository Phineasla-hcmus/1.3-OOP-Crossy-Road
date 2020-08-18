#include "StateMainMenu.h"
#include"Game.h"
#include<SFML\Graphics.hpp>
#include"Button.h"
#include"resource.h"
StateMainMenu::StateMainMenu(Game& game)
    : StateBase(game)
    , m_mainMenu(game.getWindow(), Display::HEIGHT / 2 - 100)
{
    m_banner.setSize({ 800, 100 });
    m_banner.setFillColor(sf::Color::Yellow);
    m_banner.setTexture(&resource::get().textures.get("si/crossyroad","png"));
    m_banner.setPosition(210, 30);
  
    auto playBtn = makeButton();
    playBtn->setText("Play game");
    playBtn->setFunction([&]() {
       // m_pGame->pushState<StatePlaying>(*m_pGame);
        m_pGame->exit = true;
        });

    auto highscoresBtn = makeButton();
    highscoresBtn->setText("Load Game");
    highscoresBtn->setFunction([&]() {
       // m_pGame->pushState<StateHighscores>(*m_pGame);
        m_pGame->exit = true;
        });

    auto exitBtn = makeButton();
    exitBtn->setText("Exit game");
    exitBtn->setFunction([&]() {
        m_pGame->exit = true;
        });

    m_mainMenu.addWidget(std::move(playBtn));
    m_mainMenu.addWidget(std::move(highscoresBtn));
    m_mainMenu.addWidget(std::move(exitBtn));
    m_mainMenu.setTitle("Choose Action", game.getWindow());
}

void StateMainMenu::setPosition(const sf::Vector2f position)
{
    m_container.setPosition(position);
   m_thumbnail.setPosition(position);
}
void StateMainMenu::handleEvent(sf::Event e)
{
    m_mainMenu.handleEvent(e, m_pGame->getWindow());
}
void StateMainMenu::draw(sf::RenderTarget& renderer)
{
   renderer.draw(m_container);
    renderer.draw(m_thumbnail);
}
void StateMainMenu::render(sf::RenderTarget& renderer)
{
    //m_background.draw(renderer);
    m_mainMenu.render(renderer);
    renderer.draw(m_banner);

}
