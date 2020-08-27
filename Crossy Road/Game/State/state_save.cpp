#include"../../Game/State/state_save.h"
#include"../../Framework/game.h"
state_save::state_save(Game& game,SaveInf& save)
	:state_base(game),
	save_menu(game.get_window(), 300),
	_info(save)
{
	auto name_textbox = makeTextBox(_name);
	name_textbox->setLabel("Name");
	

	auto SaveBtn = makeButton();
	SaveBtn->setText("Save Game");
	SaveBtn->setFunction([&]() {
		WritetoFile(_name);
		this->game().popState();
		});

	auto ReturnBtn = makeButton();
	ReturnBtn->setText("Return Game");
	ReturnBtn->setFunction([&]() {
		this->game().popState();
		});
	save_menu.addWidget(std::move(name_textbox));
	save_menu.addWidget(std::move(SaveBtn));
	save_menu.addWidget(std::move(ReturnBtn));
	save_menu.setTitle("     SAVE    GAME", game.get_window());

}

void state_save::handleEvent(sf::Event ev) {
	save_menu.handleEvent(ev, this->game().get_window());
}
void state_save::update(sf::Time delta_time)
{

}
void state_save::draw(sf::RenderTarget& renderer) {
	save_menu.render(renderer);
}
void state_save::WritetoFile(std::string name)
{
	std::ofstream fout;
	fout.open(SAVE_FILE_NAME + name + ".txt");
	if (fout.is_open()) {
		fout << _info.get_level() << " " << _info.get_score() << " ";
		for (int i = 0; i < save_lane; ++i)
			fout << _info.get_type(i) << " " << _info.get_speed(i);
		fout.close();
	}
	else std::cout << "CAN NOT SAVE .\n";

}