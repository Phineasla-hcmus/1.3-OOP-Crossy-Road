#include "Player.h"
#include "../world.h"
#include <algorithm>

static int initX = 0;
static int initY = 192;

Player::Player() 
	: Collision(PLAYER_SIZE/2, PLAYER_SIZE/2)
	, m_player({ PLAYER_SIZE,PLAYER_SIZE })
	, player_texture(asset::texture().get("player_sprite_2", "png"))
	, explosion(asset::texture().get("explosion", "png"))
	,death_animation(64.f,64.f)
{
	m_player.setPosition(this->origin_pos);
	m_player.setTexture(&player_texture);
	m_player.setTextureRect(sf::IntRect{ 0,192,64,64 });
	for (int index = 0; index < 5; index++) {
		death_animation.add_frame(m_delay,0,index);
	}
	death_sound.setBuffer(asset::sound().get("oofMinecraft", "ogg"));
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
			m_player.setTextureRect({ initX,initY,64,64 });
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
				m_player.setTextureRect({ initX,initY,64,64 });
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (is_walking == false)
		{
			nextspot = cur_pos.x - tile_size;
			if (nextspot <= tile_size * 2) {
				nextspot = cur_pos.x + tile_size;
				move[DOWN] = false;
				is_walking = false;;
			}
			else {
				move[LEFT] = true;
				is_walking = true;
				initY = 64;
				initX = 0;
				m_player.setTextureRect({ initX,initY,64,64 });
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (is_walking == false)
		{
			nextspot = cur_pos.x + tile_size;
			if (nextspot >= SCREEN_WIDTH - tile_size * 3) {
				nextspot = cur_pos.x - tile_size;
				move[DOWN] = false;
				is_walking = false;;
			}
			else {
				move[RIGHT] = true;
				is_walking = true;
				initY = 128;
				initX = 0;
				m_player.setTextureRect({ initX,initY,64,64 });
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
		m_player.setPosition(cur_pos.x, cur_pos.y);
	}
}

const sf::Vector2f& Player::getPosition() const
{
	return m_player.getPosition();
}

void Player::onCollide(Collision& other)
{
	is_walking = false;
	m_player.setTexture(&explosion);
	m_player.setScale(1.5f, 1.5f);
	is_Alive = false;
}

void Player::animationRenderer() {
	/*for (int col = 0; col < 4; col++) {
		for (int row = 0; row < 4; row++) {
			moveAnimation[row].add_frame(m_delay,row,col);
		}
	}*/
	if (m_clock.getElapsedTime().asSeconds() > m_delay.asSeconds() && is_walking == true && is_Alive) {
		if (initX > 192) {
			initX = 0;
			m_player.setTextureRect({ initX,initY,64,64 });
		}
		else {
			m_player.setTextureRect({ initX,initY,64,64 });
			initX += 64;
		}
		m_clock.restart();
	}
	else if (m_clock.getElapsedTime().asSeconds() > m_delay.asSeconds() && !is_Alive) {
		m_player.setTextureRect({ initX,0,64,64 });
		initX += 64;
		m_clock.restart();
	}
}

void Player::soundPlaying() {
	if (!is_Alive)
		death_sound.play();
}
void Player::draw(sf::RenderTarget& target)
{
	sf::Clock clock;
	target.draw(m_player);
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
	if (this->m_player.getGlobalBounds().top > 600)
		min_y_get_point = getPosition().y;		
		
	//score 90,270,450,630    
	if ((this->m_player.getGlobalBounds().top == 90
		|| this->m_player.getGlobalBounds().top == 270
		|| this->m_player.getGlobalBounds().top == 450)
		&& this->m_player.getGlobalBounds().top < min_y_get_point) {
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
