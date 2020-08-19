#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <functional>
#include "Widget.h"
enum class ButtonSize
{
	Small,
	Wide, 
	};
	class Button : public Widget
	{
	private:
		void updateText();
		sf::Vector2f    _pos;
		Rectangle       _button;
		Text            _text;
		std::function<void(void)> _function = []() {};//using lambdas function   
	public:
		Button(ButtonSize size = ButtonSize::Wide);
		void setFunction		(std::function<void(void)>);
		void setText            (const std::string&);
		void setTexture         (const sf::Texture&);
		void handleEvent        (sf::Event, const sf::RenderWindow&)	override;
		void render             (sf::RenderTarget&)						override;
		void setPosition        (const sf::Vector2f& pos)				override;
		sf::Vector2f getSize    () const								override;
	};
	inline std::unique_ptr<Button> makeButton() { return std::make_unique<Button>(); }

#endif // !_BUTTON_H_
