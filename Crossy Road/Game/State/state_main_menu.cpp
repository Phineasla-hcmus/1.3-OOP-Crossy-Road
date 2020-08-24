#include "state_main_menu.h"

state_main_menu::state_main_menu(Game& game)
	: state_base(game),
    m_mainMenu(game.get_window(), 300)
{
    sf::Texture title;
    title.loadFromFile("Assets/texture/crossyroad.png");
    m_banner.setSize({ 800, 100 });
    m_banner.setFillColor(sf::Color::Yellow);
    m_banner.setTexture(&title);
    m_banner.setPosition(210, 30);

    
    auto playBtn = makeButton();
    playBtn->setText("Play game");
    playBtn->setFunction([&]() {
        (this->game()).pushState(std::make_unique<state_playing>(game));
        });

    auto LoadGameBtn = makeButton();
    LoadGameBtn->setText("Load Game");
    LoadGameBtn->setFunction([&]() {
        //m_game->pushState<PauseMenu>(*m_pGame);
        //m_pGame->exit = true;
        });

    auto exitBtn = makeButton();
    exitBtn->setText("Exit game");
    exitBtn->setFunction([&]() {
       // m_game->exit = true;
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
    render.draw(m_thumbnail);
    m_mainMenu.render(render);
    render.draw(m_banner);
}
