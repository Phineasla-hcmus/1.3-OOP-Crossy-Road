#include "Object.h"



Object::Object(const sf::Vector2f& initialLocation/*, Type type*/)
    : Collidable(WIDTH, HEIGHT)
    , m_location(initialLocation)
    /*, m_type(type)*/
    , m_initialPosition(initialLocation)
{
    rect.setSize(sf::Vector2f(48.f,32.f));
    rect.setFillColor(sf::Color::Red);
}

void Object::move(float x, float y)
{
    
    m_location += {x, y};
    rect.move(m_location.x, m_location.y);
}

const sf::Vector2f& Object::getPosition() const
{
    return m_location;
}

bool Object::isAlive() const
{
    return m_isAlive;
}

//Object::Type Object::getType() const
//{
//    return m_type;
//}

void Object::onCollide(Collidable& other)
{
    m_isAlive = false;
}
