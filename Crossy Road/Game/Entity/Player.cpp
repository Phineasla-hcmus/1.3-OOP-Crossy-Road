#include "Player.h"
#include "../world.h"
#include <algorithm>

static int initX = 0;
static int initY = 192;

Player::Player() 
	: Collision(PLAYER_SIZE, 64.f)
	, people({ PLAYER_SIZE,PLAYER_SIZE })
	, move{ 0,0,0,0 }

{
	people.setPosition(this->origin_pos);
	//player_texture.loadFromFile("Assets\\textures\\player_sprite_2.png");
	player_texture = asset::texture().get("player_sprite_2", "png");

	people.setTexture(&player_texture);
	people.setTextureRect(sf::IntRect{ 0,192,64,64 });
}


void Player::keymove()
{
	/*keymove() and moving() functions are working together*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (is_walking == false)
		{
			nextspot = cur_pos.y - tile_size;
			
				move[UP] = true;
				is_walking = true;
				initY = 192;
				initX = 0;
				people.setTextureRect({ initX,initY,64,64 });
				if (nextspot == -90) {
					nextspot = origin_pos.y;
					cur_pos.y = 720;
				}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (is_walking == false)
		{
			nextspot = cur_pos.y + tile_size;
			if (nextspot >= SCREEN_HEIGHT) {
				nextspot = cur_pos.y - tile_size;
				move[DOWN] = false;
				is_walking = false;;
			}
			else {
				move[DOWN] = true;
				is_walking = true;
				initY = 0;
				initX = 0;
				people.setTextureRect({ initX,initY,64,64 });
			}
		}
		std::cout << nextspot << "\n";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (is_walking == false)
		{
			nextspot = cur_pos.x - tile_size;
			if (nextspot <= 0) {
				nextspot = cur_pos.x + tile_size;
				move[DOWN] = false;
				is_walking = false;;
			}
			else {
				move[LEFT] = true;
				is_walking = true;
				initY = 64;
				initX = 0;
				people.setTextureRect({ initX,initY,64,64 });
			}
		}
		std::cout << nextspot << "\n";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (is_walking == false)
		{
			nextspot = cur_pos.x + tile_size;
			if (nextspot >= SCREEN_WIDTH - 10) {
				nextspot = cur_pos.x - tile_size;
				move[DOWN] = false;
				is_walking = false;;
			}
			else {
				move[RIGHT] = true;
				is_walking = true;
				initY = 128;
				initX = 0;
				people.setTextureRect({ initX,initY,64,64 });
			}
		}
		std::cout << nextspot << "\n";
	}
}
void Player::moving()
{
	if (is_walking == true)
	{
		if (move[UP] == true)
		{
			cur_pos.y -= movespeed;
			if (cur_pos.y <= nextspot)
			{
				cur_pos.y = nextspot;
				is_walking = false;
				move[UP] = false;

			}
		}

		if (move[DOWN] == true )
		{
			cur_pos.y += movespeed;
			if (cur_pos.y >= nextspot)
			{
				cur_pos.y = nextspot;
				is_walking = false;
				move[DOWN] = false;
			}
		}
		if (move[LEFT] == true)
		{
			cur_pos.x -= movespeed;
			if (cur_pos.x <= nextspot)
			{
				cur_pos.x = nextspot;
				is_walking = false;
				move[LEFT] = false;
			}
		}
		if (move[RIGHT] == true)
		{
			cur_pos.x += movespeed;
			if (cur_pos.x >= nextspot)
			{
				cur_pos.x = nextspot;
				is_walking = false;
				move[RIGHT] = false;
			}
		}
		people.setPosition(cur_pos.x, cur_pos.y);
	}
}
void Player::restart()
{
	/* v_speed *= 0.0f;*/
	/* people.setTextureRect(sf::IntRect{ 0,192,64,64 });*/
	is_Alive = true;
	is_walking = false;
	people.setPosition(this->origin_pos);
	cur_pos = this->origin_pos;
}



void Player::update(unsigned int& level, unsigned int& score)
{
	if (this->people.getGlobalBounds().top <= -this->people.getGlobalBounds().height) {
		++level;
		score += 10;
		this->restart();


		//if player move out of bound

		//Left
		if (this->people.getGlobalBounds().left <= 10.f)
			this->people.setPosition(10.f, this->people.getGlobalBounds().top);
		// 
		//Right
		if (this->people.getGlobalBounds().left + this->people.getGlobalBounds().width >= 1270.f)
			this->people.setPosition(1270 - this->people.getGlobalBounds().width, this->people.getGlobalBounds().top);
		//
		//Top
		if (this->people.getGlobalBounds().top <= -this->people.getGlobalBounds().height) {
			this->people.setPosition(this->people.getGlobalBounds().left, 720 - this->people.getGlobalBounds().height);
			cur_pos.y = origin_pos.y;
			/*World::levelUp();
			World::plusScore();*/
		}
		//Bottom
		if (this->people.getGlobalBounds().top + this->people.getGlobalBounds().height > 720) {
			this->people.setPosition(this->people.getGlobalBounds().left, 720 - this->people.getGlobalBounds().height);
			cur_pos.y = origin_pos.y;

		}
		if (this->people.getGlobalBounds().top > 600)
			min_y_get_point = this->people.getGlobalBounds().top;


		//score 90,270,450,630    
		if (this->people.getGlobalBounds().top == 450 && this->people.getGlobalBounds().top < min_y_get_point) {
			score += 10;
			min_y_get_point = this->people.getGlobalBounds().top;
		}
		else if (this->people.getGlobalBounds().top == 270 && this->people.getGlobalBounds().top < min_y_get_point) {
			score += 10;
			min_y_get_point = this->people.getGlobalBounds().top;

		}
		else if (this->people.getGlobalBounds().top == 90 && this->people.getGlobalBounds().top < min_y_get_point) {
			score += 10;
			min_y_get_point = this->people.getGlobalBounds().top;
		}

	}
}
void Player::animationRenderer() {
	if (m_clock.getElapsedTime().asSeconds() > m_gaps && is_walking == true) {
		if (initX > 192) {
			initX = 0;
			people.setTextureRect({ initX,initY,64,64 });
		}
		else {
			people.setTextureRect({ initX,initY,64,64 });
			initX += 64;
		}
		m_clock.restart();
	}
}


void Player::draw(sf::RenderTarget& target)
{
	sf::Clock clock;
	if (!is_Alive) {
		//people.setTextureRect(death_Animation.getFrame());
	}
	target.draw(people);
}




bool Player::isAlive() const
{
	return is_Alive;
}
