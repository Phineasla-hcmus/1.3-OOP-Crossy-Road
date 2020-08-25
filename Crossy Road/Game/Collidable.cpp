#include "Collidable.h"
#include "Collidable.h"


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
