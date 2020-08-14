#include "RigidBody.h"
RigidBody::RigidBody(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position) {
	body.setTexture(texture);
	body.setOrigin(size / 2.0f);
	body.setSize(size);
	body.setPosition(position);
}
RigidBody::~RigidBody() {}

void RigidBody::Draw(sf::RenderWindow& window){
	window.draw(body);
}