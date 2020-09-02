#include "Player.h"
#include "../world.h"
#include <algorithm>

static int initX = 0;
static int initY = 192;

Player::Player() 
	: Collision(45.f, PLAYER_SIZE)
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
			if (nextspot == -tile_size) {
				nextspot = origin_pos.y;
				cur_pos.y = SCREEN_HEIGHT;
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
//void Player::restart()
//{
//	/* v_speed *= 0.0f;*/
//	/* people.setTextureRect(sf::IntRect{ 0,192,64,64 });*/
//	is_Alive = true;
//	is_walking = false;
//	people.setPosition(this->origin_pos);
//	cur_pos = this->origin_pos;
//}



//void Player::update(uint& level, uint& score)
//{
//	if (this->people.getGlobalBounds().top <= -90) {

//<<<<<<< HEAD
//		++level;
//		score += 10;
//		/*this->restart();*/
//
//		level=1;
//		score = 10;
//		this->restart();
//>>>>>>> 4c274ad04f643f8fe18e5303d212977b0a1e94f3

//		++level;
//		score += 10;
//		/*this->restart();*/

//	}
//
//	//if player move out of bound
//

//	

//	//Top
//	if (this->people.getGlobalBounds().top <= -this->people.getGlobalBounds().height) {
//		this->people.setPosition(this->people.getGlobalBounds().left, 720 - this->people.getGlobalBounds().height);
//		cur_pos.y = origin_pos.y;
//		/*World::levelUp();
//		World::plusScore();*/
//	}
//	if (this->people.getGlobalBounds().top > 600)
//		min_y_get_point = this->people.getGlobalBounds().top;

//	if (this->people.getGlobalBounds().top > 600)
//		min_y_get_point = this->people.getGlobalBounds().top;
//
//
//	//score 90,270,450,630    
//	if (this->people.getGlobalBounds().top == 450 && this->people.getGlobalBounds().top < min_y_get_point) {

//		score = 10;
//		min_y_get_point = this->people.getGlobalBounds().top;
//	}
//	else if (this->people.getGlobalBounds().top == 270 && this->people.getGlobalBounds().top < min_y_get_point) {
//		score = 10;

//		score += 10;
//		min_y_get_point = this->people.getGlobalBounds().top;
//	}
//	else if (this->people.getGlobalBounds().top == 270 && this->people.getGlobalBounds().top < min_y_get_point) {
//		score += 10;

//		min_y_get_point = this->people.getGlobalBounds().top;
//
//	}
//	else if (this->people.getGlobalBounds().top == 90 && this->people.getGlobalBounds().top < min_y_get_point) {

//		score = 10;

//		score += 10;

//		min_y_get_point = this->people.getGlobalBounds().top;
//	}
//
//}
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

bool Player::isPassLevel() const
{
	return m_passed;
}

void Player::update()
{
	if (this->people.getGlobalBounds().top > 600)
		min_y_get_point = getPosition().y;		
		
	//score 90,270,450,630    
	if ((this->people.getGlobalBounds().top == 90
		|| this->people.getGlobalBounds().top == 270
		|| this->people.getGlobalBounds().top == 450)
		&& this->people.getGlobalBounds().top < min_y_get_point) {
		min_y_get_point = getPosition().y;
		m_get_score = true;
	}
	else
		m_get_score = false;
	if (getPosition().y <= SCREEN_HEIGHT && getPosition().y > SCREEN_HEIGHT - 5) {
		m_passed = true;
		m_get_score = true;
	}
}

bool Player::isGetScore() const
{
	return m_get_score;
}

void Player::restart()
{
	m_passed = false;
	m_get_score = false;
	min_y_get_point = 720.f;
}
