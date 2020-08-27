#ifndef Player_h
#define Player_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"../../Framework/AssetManager/asset.h"
#include "../Collidable.h"
#include <iostream>

/*
	Represents the player
*/
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
	sf::Vector2f origin_pos = { 640, 720 - 90 };

	bool is_Alive = true;
	sf::Texture player_texture;


	float x;
	float y;
	float movespeed; //sets the movespeed

	enum MOVE { UP, DOWN, LEFT, RIGHT }; //enums instead of remember numbers
	bool move[4]; //deciding if u move up/down/left/right
	bool is_walking;
	int nextspot; //the next tilespot of the map
};

#endif