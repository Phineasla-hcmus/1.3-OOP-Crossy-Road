#include"state_save.h"
state_save::state_save(Game& game, SaveInf& save)
	:state_base(game),
	save_menu(game.get_window(), 300),
	m_save(save)
{
	auto name_textbox = makeTextBox(m_name);
	name_textbox->setLabel("Name");


	auto SaveBtn = makeButton();
	SaveBtn->setText("Save Game");
	SaveBtn->setFunction([&]() {
		saveGame(m_name, m_save);
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
void state_save::WritetoFile(std::string name="default")
{
	std::ofstream fout;
	fout.open(SAVE_FILE_NAME + name + ".bin", std::ios::binary);
	if (fout.is_open()) {
		auto test = m_save.get_level();
		fout.write((char*)&test, sizeof(int));
		fout.write((char*)(m_save.get_score()), sizeof(int));
		for (int i = 0; i < SAVE_LANE; ++i) {
			 const SaveInf::RoadInf a = m_save.get_RoadInf(i);
			fout.write((char*)&a, sizeof(SaveInf::RoadInf));
		}
		fout.close();
	}
	else std::cout << "CAN NOT SAVE .\n";

}