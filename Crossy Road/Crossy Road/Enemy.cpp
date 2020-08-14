#include "Enemy.h"
void Enemy::initSpeed() {
	body.setSize(Vector2f(50.f, 50.f));
	this->body.setFillColor(Color::Red);
	speed = rand() % (10 - 1) + 1.0f;
}
<<<<<<< Updated upstream
void Enemy::initRow() {

}
=======
void Enemy::initRow() {}

>>>>>>> Stashed changes
void Enemy::Update(RenderWindow& window) {
	window.draw(this->body);
	this->body.move(Vector2f(speed, 0.f));
}
<<<<<<< Updated upstream
Enemy::Enemy(float x, float y,RectangleShape rec) {
	body = rec;
	this->initSpeed();
	this->body.setPosition(x, y);

}

=======
Enemy::Enemy(float x, float y, RenderWindow& window)  {

	this->initSpeed();
	this->body.setPosition(x, y);
	window.draw(this->body);
}
void Enemy::Render(RenderTarget& target) {
	target.draw(this->body);
}
>>>>>>> Stashed changes
const FloatRect Enemy::getBounds() const {
	return body.getGlobalBounds();
}
Enemy::~Enemy() {}