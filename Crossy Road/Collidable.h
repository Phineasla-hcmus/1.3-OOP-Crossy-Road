
#include <SFML/Graphics.hpp>
#include "../Crossy Road/Entity/Vehicle.h"
class Collidable
{
public:
    Collidable(float width, float height);
    bool tryCollideWith(Collidable& other);
    sf::FloatRect getBox() const;

    virtual const sf::Vector2f& getPosition() const = 0;
    virtual void onCollide(Collidable& other) = 0;

private:
    sf::Vector2f m_size;
};
