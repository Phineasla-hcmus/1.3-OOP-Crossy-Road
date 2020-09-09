#include "Widget.h"
#include "../AssetManager/asset.h"
Widget::Text::Text()
	: Text(DEFAULT_FONT, DEFAULT_EXT,
		TEXT_SIZE,
		OUTLINE_COLOR, FILL_COLOR)
{}
Widget::Text::Text(const std::string& font, const std::string& ext, unsigned size, const sf::Color& outline, const sf::Color& fill)
{
	setCharacterSize(size);
	setOutlineColor(outline);
	setFillColor(fill);
	setOutlineThickness(2);
	setFont(asset::font().get(font, ext));
}
void Widget::Text::_setFont(const std::string& font = BACKUP_FONT, const std::string& ext = BACKUP_EXT)
{
	setFont(asset::font().get(font, ext));
}
bool Widget::Rectangle::isRolledOn(const sf::RenderWindow& window) const
{
	auto pos = sf::Mouse::getPosition(window);
	return getGlobalBounds().contains((float)pos.x, (float)pos.y);
}

bool Widget::Rectangle::isClicked(sf::Event ev, const sf::RenderWindow& window)
{
	if (isRolledOn(window)) {
		if (ev.type == sf::Event::MouseButtonPressed) {
			return ev.mouseButton.button == sf::Mouse::Left;
		}
	}
	return false;
}

