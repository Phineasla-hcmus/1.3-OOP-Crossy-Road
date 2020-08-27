#include "Collidable.h"

Collision::Collision(const sf::Vector2f& size)
    : m_size(size)
{}

Collision::Collision(float width, float height)
    : m_size(width, height)
{}

bool Collision::tryCollideWith(Collision& other)
{
    if (getBox().intersects(other.getBox())) {
        onCollide(other);
        other.onCollide(*this);
        return true;
    }
    return false;
}

void Collision::setSize(sf::Vector2f new_size)
{
    m_size = new_size;
}

sf::FloatRect Collision::getBox() const
{
    return
    {
        getPosition().x,
        getPosition().y,
        m_size.x,
        m_size.y
    };
}

void Collision::onCollide(Collision& other)
{}
