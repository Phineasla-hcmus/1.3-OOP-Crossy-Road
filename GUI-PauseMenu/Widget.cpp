#include "Widget.h"
#include"resource.h"
Widget::Text::Text()
{
    setCharacterSize(30);
    setOutlineColor(sf::Color::Black);
    setFillColor(sf::Color::Blue);
    setFont(resource::get().fonts.get("arcade","TTF"));
    
}

bool Widget::Rectangle::isRolledOn(const sf::RenderWindow& window) const
{
    auto pos = sf::Mouse::getPosition(window);
    return getGlobalBounds().contains((float)pos.x, (float)pos.y);
}

bool Widget::Rectangle::isClicked(sf::Event e, const sf::RenderWindow& window)
{
    if (isRolledOn(window)) {
        if (e.type == sf::Event::MouseButtonPressed) {
            return e.mouseButton.button == sf::Mouse::Left;
        }
    }
    return false;
}

