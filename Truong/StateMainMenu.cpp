#include "StateMainMenu.h"
#include"Game.h"
#include<SFML\Graphics.hpp>
StateMainMenu::StateMainMenu(Game& game) : StateBase(game, "Main Menu", 1280, 720)
{
    m_banner.setSize({ 720/2, 1280/2 });
    m_banner.setFillColor(sf::Color::Blue);
    m_banner.setPosition(100, 100);
}
void StateMainMenu::onOpen()
{
    m_pGame->resizeWindow(1280, 720);

}
void StateMainMenu::setPosition(const sf::Vector2f position)
{
    m_container.setPosition(position);
    m_thumbnail.setPosition(position);
}

void StateMainMenu::draw(sf::RenderTarget& renderer)
{
    renderer.draw(m_container);
    renderer.draw(m_thumbnail);
}
void StateMainMenu::render(sf::RenderTarget& renderer)
{
    renderer.draw(m_banner);

}
