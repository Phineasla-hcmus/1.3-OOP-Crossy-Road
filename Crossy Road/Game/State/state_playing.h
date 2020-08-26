#ifndef _state_playing
#define _state_playing
#include"../../Framework/State/state_base.h"
#include"../../Framework/GUI/Widget.h"
#include"../../Game/State/state_pause.h"
#include "../World.h"
#include"state_load.h"

class state_playing :public state_base {
private:
	World	m_world;
	int		m_score			= 0;
	bool	m_is_gameover	= false;
	bool    _is_paused      = false;
	int		m_level = 1;
	PauseMenu pause_menu;
	SaveInf save;
	class display {
	private:
		Widget::Text label;
		std::string  text;
		int currentdata;
		float centrepoint;
		void updateDisplay();
	public:
		display(float centreY, const std::string& text);
		void update(int newdata);
		void draw(sf::RenderTarget& target);
		int getCurrentDataDisplayed() const;
	}_score_display, _level_display;
public:
	state_playing(Game&);
	state_playing(Game&, SaveInf);

	void handleEvent(sf::Event e)			override;
	void handleInput()                      override;
	void update(sf::Time delta_time)		override;	
	void draw(sf::RenderTarget& renderer)    override;
};

#endif // !_state_playing/
