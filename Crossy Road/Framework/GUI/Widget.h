#ifndef _WIDGET_H_
#define _WIDGET_H_
#include <SFML/Graphics.hpp>
#include <memory>
//default value
#define	TEXT_SIZE		30
#define	OUTLINE_COLOR	sf::Color::Black
#define FILL_COLOR		sf::Color::Blue
#define DEFAULT_FONT	"arcade"
#define DEFAULT_EXT		"TTF"
#define BACKUP_FONT	    "FAIL"
#define BACKUP_EXT		"TTF"
class Widget
{
public:
	virtual void handleEvent(sf::Event e, const sf::RenderWindow& window)   = 0;
	virtual void render     (sf::RenderTarget& renderer)                    = 0;
	virtual void setPosition(const sf::Vector2f& pos)                       = 0;
	virtual sf::Vector2f getSize() const                                    = 0;
	class Text : public sf::Text
	{
	public:
		Text();
		Text(const std::string& font, 
			const std::string& ext,
			unsigned size,
			const sf::Color& outline, 
			const sf::Color& fill);
		void _setFont(const std::string& font,
			const std::string& ext);
	};
	class Rectangle : public sf::RectangleShape
	{
	public:
		bool isRolledOn(const sf::RenderWindow& window) const;
		bool isClicked(sf::Event, const sf::RenderWindow& window);
	};
};

#endif //!_WIDGET_H_
