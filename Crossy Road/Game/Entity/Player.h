#ifndef Player_h
#define Player_h

#include"../../PCH.h"
#include "../Collidable.h"
#include "SFML/Audio.hpp"
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
	/*void update(uint& level, uint& score);*/
	void draw(sf::RenderTarget& target);
	void keymove(); //keypress detection
	void moving(); //moving if "walking" boolean is true
	const sf::Vector2f& getPosition() const { return m_player.getPosition(); };
	void onCollide(Collision& other) override { is_Alive = false; }
	void animationRenderer();
	bool isAlive() const;
	sf::Vector2f getPosition() { return cur_pos; };
	/*void restart();*/
	bool isPassLevel()const;
	void update();
	bool isGetScore()const;
	void restart();
	void soundPlaying();
private:
	sf::RectangleShape m_player;
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
	sf::Texture& player_texture;
	sf::Texture& explosion;
	float min_y_get_point;
	bool m_passed = false;
	bool m_get_score = false;

	sf::Sound death_sound;
	sf::Sound walking_sound;
};

#endif