#include "Player.h"

Player::Player()  {
	this->movementSpeed = 10.f;
	body.setSize(Vector2f(50.f, 50.f));
	body.setPosition(Vector2f(400.f, 200.f));
	body.setFillColor(Color::Green);
}
void Player::move(const float x, const float y) {
	this->body.move(x * this->movementSpeed, y * this->movementSpeed);
}
Player::~Player() {}
//Player::Player(sf::RectangleShape& body) :body(body) {
//	this->body = body;
//}
void Player::Render(RenderTarget& target) {
	target.draw(this->body);
}
void Player::Update() {

}

//void Player::Draw(sf::RenderWindow window) {
//	window.draw(this->body);
//}