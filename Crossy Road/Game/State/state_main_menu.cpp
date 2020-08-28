#include "state_main_menu.h"
#include "state_playing.h"
#include "state_load.h"
state_main_menu::state_main_menu(Game& game)
    : state_base(game)
    , m_mainMenu(game.get_window(), 300)
    , m_background(asset::texture().get("background768", "png"), { 768,448 }, { 8,12 })
{

    m_banner.setSize({ 800, 150 });
    m_banner.setFillColor(sf::Color::White);
    m_banner.setOutlineColor(sf::Color::Black);
    m_banner.setTexture(&asset::texture().get("crossyroad2", "png"));
    m_banner.setPosition(220, 30);

    
    auto playBtn = makeButton();
    playBtn->setText("Play game");
    playBtn->setFunction([&]() {
        (this->game()).pushState(std::make_unique<state_playing>(game));
        });

    auto LoadGameBtn = makeButton();
    LoadGameBtn->setText("Load Game");
    LoadGameBtn->setFunction([&]() {
       
        });

    auto exitBtn = makeButton();
    exitBtn->setText("Exit game");
    exitBtn->setFunction([&]() {
        this->game().popState();
        });

    m_mainMenu.addWidget(std::move(playBtn));
    m_mainMenu.addWidget(std::move(LoadGameBtn));
    m_mainMenu.addWidget(std::move(exitBtn));
    m_mainMenu.setTitle("Choose  Action", game.get_window());
}

void state_main_menu::handleEvent(sf::Event ev)
{
    m_mainMenu.handleEvent(ev,this->game().get_window());
}

void state_main_menu::update(sf::Time delta_time)
{

}

void state_main_menu::draw(sf::RenderTarget& render)
{
    m_background.draw(render);
    m_mainMenu.render(render);
    render.draw(m_banner);
}
