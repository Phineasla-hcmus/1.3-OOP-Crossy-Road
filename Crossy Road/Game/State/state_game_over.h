#ifndef _STATE_GAME_OVER_H_
#define _STATE_GAME_OVER_H_
#include"../../PCH.h"
const  std::string Score_label ="SCORE";
const std::string HighScore_label ="HIGH SCORE";
const std::string NewHighScore_label = "NEW \n HIGH SCORE";

class game_over :public state_base {
private:
	StackMenu m_gameover_menu;
	bool m_exit = false;
	Widget::Text label;
	Widget::Text m_score;
	Widget::Text m_highscore;
	sf::RectangleShape container;

	int score = 10;
	int highscore = 1000;
public:
	game_over(Game&);

	bool GetState();
	void  draw(sf::RenderTarget& target)    override;
	void handleEvent(sf::Event e)		   override;
	void update(sf::Time dental_time)		override;
	void updateScore(int _score);
	
};
#endif // !_STATE_GAME_OVER_H_
