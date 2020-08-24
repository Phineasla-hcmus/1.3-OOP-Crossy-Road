#include "PauseMenu.h"
#include"Game.h"
#include"StackMenu.h"
#include"StateBase.h"
#include<iostream>
PauseMenu::PauseMenu(Game& game)
	: StateBase(game),pause_menu(game.getWindow(), Display::HEIGHT/2 - 100)
{
	
	auto ResumeBtn = makeButton();
	ResumeBtn->setText("Resume     ");
	ResumeBtn->setFunction([&]() {
		is_paused = false;
		});
	auto SaveGameBtn = makeButton();
	SaveGameBtn->setText("Save Game");
	SaveGameBtn->setFunction([&]() {
		 m_pGame->pushState<StateMainMenu>(*m_pGame);
		});
	auto LoadGameBtn = makeButton();
	LoadGameBtn->setText("Load Game");
	LoadGameBtn->setFunction([&]() {
		m_pGame->pushState<StateMainMenu>(*m_pGame);
		});

	pause_menu.addWidget(std::move(ResumeBtn));
	pause_menu.addWidget(std::move(SaveGameBtn));
	pause_menu.addWidget(std::move(LoadGameBtn));
	pause_menu.setTitle("   PAUSE  MENU", game.getWindow());
}

void PauseMenu::update(const sf::Vector2f& mousePos) {
	
}
void PauseMenu::draw(sf::RenderTarget& target) {
	
	
	pause_menu.render(target);
}
void PauseMenu::handleEvent(sf::Event e){
	
	pause_menu.handleEvent(e, m_pGame->getWindow());
	
	
}
bool PauseMenu:: isPaused() {
	return is_paused;
}
void PauseMenu::changeState() {
	is_paused= true;
}
//void update(sf::Time deltaTime) {}