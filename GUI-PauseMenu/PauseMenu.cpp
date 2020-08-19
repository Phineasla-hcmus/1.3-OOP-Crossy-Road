#include "PauseMenu.h"
#include"Game.h"
#include"StackMenu.h"
#include"StateBase.h"
PauseMenu::PauseMenu(Game& game)
	: StateBase(game),pause_menu(game.getWindow(), Display::HEIGHT / 2 - 100)
{

	auto ResumeBtn = makeButton();
	ResumeBtn->setText("Resume     ");
	ResumeBtn->setFunction([&]() {
		//m_pGame->pushState<StateMainMenu>(*m_pGame);
		m_pGame->exit = true;
		});

	auto SaveGameBtn = makeButton();
	SaveGameBtn->setText("Save Game");
	SaveGameBtn->setFunction([&]() {
		 //m_pGame->pushState<StateMainMenu>(*m_pGame);
		});
	auto LoadGameBtn = makeButton();
	LoadGameBtn->setText("Load Game");
	LoadGameBtn->setFunction([&]() {
		});

	this->pause_menu.addWidget(std::move(ResumeBtn));
	this->pause_menu.addWidget(std::move(SaveGameBtn));
	this->pause_menu.addWidget(std::move(LoadGameBtn));
	this->pause_menu.setTitle("   PAUSE  MENU", game.getWindow());
}
//PauseMenu::~PauseMenu() {
//	/*auto it = this->buttions.begin();
//	for (it = this->buttions.begin(); it != this->buttions.end(); ++it) {
//		delete it->second;
//	}*/
//}
void PauseMenu::update() {

}
void PauseMenu::render(sf::RenderTarget& target) {
	/*target.draw(this->background);
	target.draw(this->container);*/
	pause_menu.render(target);
}

