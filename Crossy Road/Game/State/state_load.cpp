#include "state_load.h"
#include"state_playing.h"

state_load::state_load(Game& game)
	: state_base(game),
	load_menu(game.get_window(), 300),
	load_inf()
{
	auto Load_Textbox = makeTextBox(link);
	Load_Textbox->setLabel("LINK");

	auto LoadBtn = makeButton();
	LoadBtn->setText("Load Game");
	LoadBtn->setFunction([&]() {
		//this->game().pushState(std::make_unique<state_playing>(game, load_inf));
		});

	auto ReturnBtn = makeButton();
	ReturnBtn->setText("Return");
	ReturnBtn->setFunction([&]() {
		this->game().popState();
		});
	load_menu.addWidget(std::move(Load_Textbox));
	load_menu.addWidget(std::move(LoadBtn));
	load_menu.addWidget(std::move(ReturnBtn));
	load_menu.setTitle("    Load   Menu", game.get_window());

}
void state_load::handleEvent(sf::Event e)
{
	load_menu.handleEvent(e, this->game().get_window());
}

void state_load::update(sf::Time delta_time)
{
}

void state_load::draw(sf::RenderTarget& renderer)
{
	load_menu.render(renderer);
}
