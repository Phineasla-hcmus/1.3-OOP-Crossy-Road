#include "Collidable.h"

namespace SpaceInvaders
{
    Collidable::Collidable(float width, float height)
        : size(width, height)
    {}

    bool Collidable::tryCollideWith(Collidable& other)
    {
        if (getBox().intersects(other.getBox())) {
            onCollide(other);
            other.onCollide(*this);
            return true;
        }
        return false;
    }

    sf::FloatRect Collidable::getBox() const
    {
        return
        {
            getPosition().x,
            getPosition().y,
            size.x,
            size.y
        };
    }
}