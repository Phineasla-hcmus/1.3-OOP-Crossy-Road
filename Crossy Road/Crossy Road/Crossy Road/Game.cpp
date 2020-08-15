#include "Game.h"
void Game::initWindow() {
	this->window = new RenderWindow(VideoMode(800, 600), "Crossy Road", Style::Close | Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
	this->window->setKeyRepeatEnabled(false);
}
bool Game::Collision() {
	Collider en(enemy->getCollider());
	Collider pl(player->getCollider());
	if (en.checkInterect()) {
		cout << "Collided!" << endl;
		return true;
	}
	return false;
}
void Game::initPlayer() {
	this->player = new Player();

	this->enemy = new Enemy(400.f, 100.f, *window);
}
Game::Game() {
	this->initWindow();
	this->initPlayer();
}
Game::~Game() {
	delete this->window;
	delete this->player;
}
void Game::run() {
	while (this->window->isOpen()) {
		GameOver = false;
		this->Update();
		this->Render();
	}
}
void Game::Update() {
	Event ev;
	while (this->window->pollEvent(ev)) {
		switch (ev.type) {
		case sf::Event::Closed:
			this->window->close();
		case sf::Event::TextEntered:
			if (ev.text.unicode < 128) {
				std::cout << ev.text.unicode << std::endl;
			}
		case sf::Event::KeyPressed:
			switch (ev.key.code) {
			case (sf::Keyboard::Up): {
				this->player->move(0.f, -1.f);
				break;
			}
			case (sf::Keyboard::Down): {
				this->player->move(0.f, 1.f);
				break;
			}
			case (sf::Keyboard::Left): {
				this->player->move(-1.f, 0.f);
				break;
			}
			case (sf::Keyboard::Right): {
				this->player->move(1.f, 0.f);
				break;
			}
			case sf::Event::KeyReleased:
				break;
			}
		}
	}
	
}
void Game::Render() {
	this->window->clear();

	this->player->Render(*this->window);

	this->enemy->Render(*this->window);
	this->window->display();
}