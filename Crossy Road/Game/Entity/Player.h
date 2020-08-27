#ifndef Player_h
#define Player_h

#include"../../PCH.h"
#include "../Collidable.h"
#include <iostream>

/*
	Represents the player
*/
constexpr auto START_X	= screen_width / 2;
constexpr auto START_Y	= screen_height - tile_size;
constexpr auto MOVESPEED = 3.f;
constexpr auto PLAYER_SIZE = tile_size - 10;
class Player :public Collision
{
public:
	//constexpr static int WIDTH = 44;
	//constexpr static int HEIGHT = 32;

	Player();
	void update(float dt);
	void draw(sf::RenderTarget& target);
	void keymove(); //keypress detection
	void moving(); //moving if "walking" boolean is true
	const sf::Vector2f& getPosition() const { return people.getPosition(); };
	void onCollide(Collision& other) override { is_Alive = false; }
	void animationRenderer();
	bool isAlive() const;

private:
	void restart();

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
};

#endif