#include "../../Game/State/state_pause.h"
#include"../../Framework/game.h"

PauseMenu::PauseMenu(Game& game, SaveInf& _info)
	: state_base(game),
	pause_menu(game.get_window(),300)
{
	
	auto ResumeBtn = makeButton();
	ResumeBtn->setText("Resume     ");
	ResumeBtn->setFunction([&]() {
		is_paused = false;
		});
	auto SaveGameBtn = makeButton();
	SaveGameBtn->setText("Save Game");
	SaveGameBtn->setFunction([&]() {
		(this->game()).pushState(std::make_unique<state_save>(game,_info));
		});
	auto LoadGameBtn = makeButton();
	LoadGameBtn->setText("Load Game");
	LoadGameBtn->setFunction([&]() {
		//(this->game()).pushState(std::make_unique<state_playing>(game));
		});

	pause_menu.addWidget(std::move(ResumeBtn));
	pause_menu.addWidget(std::move(SaveGameBtn));
	pause_menu.addWidget(std::move(LoadGameBtn));
	pause_menu.setTitle("   PAUSE  MENU", game.get_window());
}
void PauseMenu::update(sf::Time dental_time) {

}

void PauseMenu::draw(sf::RenderTarget& target) {
	
	pause_menu.render(target);
}
void PauseMenu::handleEvent(sf::Event ev){
	
	pause_menu.handleEvent(ev,this->game().get_window());
	
}
bool PauseMenu:: isPaused() {
	return is_paused;
}
void PauseMenu::changeState() {
	is_paused= !is_paused;
}
//void update(sf::Time deltaTime) {}