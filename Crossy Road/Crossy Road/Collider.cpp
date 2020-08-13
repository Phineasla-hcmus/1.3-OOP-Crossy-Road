#include "Collider.h"

Collider::Collider(float width, float height)
    : m_size(width, height)
{
}

    bool Collider::tryCollideWith(Collider& other)
    {
        if (getBox().intersects(other.getBox())) {
            onCollide(other);
            other.onCollide(*this);
            return true;
        }
        return false;
    }

    sf::FloatRect Collider::getBox() const
    {
        return
        {
            getPosition().x,
            getPosition().y,
            m_size.x,
            m_size.y
        };
    }
