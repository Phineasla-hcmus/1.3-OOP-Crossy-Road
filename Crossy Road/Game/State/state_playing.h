#pragma once

#include "../../Framework/State/state_base.h"
#include "../World.h"
#include "../../Framework/GUI/StackMenu.h"



 class state_playing : public state_base
    {
    public:
        state_playing(game& game);

        void handleEvent(sf::Event e)                   override;
        void handleInput()                              override;
        void update(sf::Time deltaTime)            override;
        void render(sf::RenderTarget& renderer)    override;

    private:
        World m_world;

        int m_score = 0;
        bool m_isGameover;
        sf::Clock m_gameOverClock;

        StackMenu m_gameOverMenu;

        //Displays how many lives the player has left
        class LifeDisplay
        {
        public:
            LifeDisplay();

            void draw(sf::RenderTarget& window, int lives);

        private:
            Widget::Text m_label;
            sf::RectangleShape m_lifeStamp;
        } m_lifeDisplay;

        //Displays the Player's current score
        class ScoreDisplay
        {
        public:
            ScoreDisplay(float centreX, const std::string& text);
            

            void update(int newScore);

            void draw(sf::RenderTarget& target);

            int getCurrentScoreDisplayed() const;
        private:
            void updateDisplay();

<<<<<<< HEAD
            Widget::Text m_label;
            std::string m_text;
            int m_currentScore;
            float m_centerPosition;
        } m_scoreDisplay, m_highestScoreDisplay;
    };
=======
class state_playing :public state_base {
private:
	World _world;
	int		_score			= 0;
	bool	_is_gameover	= false;
public:
	state_playing(game&);

	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget& renderer)	override;
};
#endif // !_state_playing
>>>>>>> parent of ff83bed... backup state playing
