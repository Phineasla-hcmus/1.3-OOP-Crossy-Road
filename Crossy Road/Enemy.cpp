#include "Enemy.h"
Enemy::Enemy(const sf::Vector2f& initLocation)
	:Collider(100, 50)
	,m_initialPosition(initLocation)
	,m_location(initLocation)
{
	body.setSize(sf::Vector2f(100.f, 50.f));
}

void Enemy::move(float x) {
	m_location += {x, 0};
}


bool Enemy::isActive() const {
	if (body.getGlobalBounds().left < 0.f)
		return false;
	return m_isActive;
}
const sf::Vector2f& Enemy::getPosition() const{
	return m_location;
}


void Enemy::onCollide(Collider& other) {
	m_isActive = false;
}

