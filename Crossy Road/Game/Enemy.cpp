#include "Enemy.h"
void Enemy::initSpeed() {
	body.setSize(Vector2f(50.f, 50.f));
	this->body.setFillColor(Color::Red);
	speed = rand() % (10 - 1) + 1.0f;
}
void Enemy::initRow() {

}
void Enemy::Update(RenderWindow& window) {
	window.draw(this->body);
	this->body.move(Vector2f(speed, 0.f));
}
Enemy::Enemy(float x, float y,RectangleShape rec) {
	body = rec;
	this->initSpeed();
	this->body.setPosition(x, y);

}

const FloatRect Enemy::getBounds() const {
	return body.getGlobalBounds();
}
Enemy::~Enemy() {}