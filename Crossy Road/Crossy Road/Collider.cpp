#include "Collider.h"
bool Collider::checkInterect(const FloatRect& fr) {
	return this->hitbox.getGlobalBounds().intersects(fr);
}
Collider::Collider(Sprite& sprite, float x, float y, float width, float height) :sprite(sprite),offsetX(x),offsetY(y) {
	this->hitbox.setPosition(this->sprite.getPosition().x + x, this->sprite.getPosition().y + y);
	this->hitbox.setSize(Vector2f(width, height));
	this->hitbox.setFillColor(Color::Transparent);
	this->hitbox.setOutlineThickness(1.f);
	this->hitbox.setOutlineColor(Color::Blue);
}
void Collider::Update() {
	this->hitbox.setPosition(this->sprite.getPosition().x + this->offsetX, this->sprite.getPosition().y + this->offsetY);
}
void Collider::Render(RenderTarget& target) {
	target.draw(this->hitbox);
}
Collider::~Collider() {

}