#ifndef Player_h
#define Player_h

#include"../../PCH.h"
#include "../Collidable.h"
#include <iostream>

/*
	Represents the player
*/
constexpr auto START_X	= SCREEN_WIDTH / 2;
constexpr auto START_Y	= SCREEN_HEIGHT - tile_size;
constexpr auto MOVESPEED = 3.f;
constexpr auto PLAYER_SIZE = tile_size - 10;
class Player :public Collision
{
public:
	//constexpr static int WIDTH = 44;
	//constexpr static int HEIGHT = 32;

	Player();
	void update(unsigned int& level, unsigned int& score);
	void draw(sf::RenderTarget& target);
	void keymove(); //keypress detection
	void moving(); //moving if "walking" boolean is true
	const sf::Vector2f& getPosition() const { return people.getPosition(); };
	void onCollide(Collision& other) override { is_Alive = false; }
	void animationRenderer();
	bool isAlive() const;
	void restart();

private:
	

	sf::RectangleShape people;
	sf::Clock m_clock;
	float m_gaps = 0.1f;
	sf::Vector2f origin_pos = { START_X, START_Y };
	sf::Vector2f cur_pos = { START_X,START_Y };
	float movespeed = MOVESPEED;

	enum MOVE { UP, DOWN, LEFT, RIGHT }; //enums instead of remember numbers
	bool move[4]; //deciding if u move up/down/left/right
	bool is_walking = false;
	float nextspot; //the next tilespot of the map

	bool is_Alive = true;
	sf::Texture player_texture;
	float min_y_get_point;
};

#endif