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


