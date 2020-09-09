#include "Vehicle.h"


Vehicle::Vehicle(sf::Vector2f pos, const sf::Texture& texture)
	: Collision((float)texture.getSize().x, (float)texture.getSize().y)
	, m_sprite(sf::Vector2f((float)texture.getSize().x, (float)texture.getSize().y))
	, m_active(true)
{
	m_sprite.setPosition(pos);
	setTexture(texture);
}

Vehicle::Vehicle(sf::Vector2f pos , const sf::Texture& texture, sf::IntRect textureBound)
	: Collision((float)textureBound.width, (float)textureBound.height)
	, m_sprite(sf::Vector2f((float)textureBound.width, (float)textureBound.height))
{
	m_sprite.setPosition(pos);
	setTexture(texture, textureBound);
}

const sf::Vector2f& Vehicle::getSize() const
{
	return m_sprite.getSize();
}

void Vehicle::setTexture(const sf::Texture& texture, const sf::IntRect& bounds)
{
	m_sprite.setTexture(&texture);
	m_sprite.setTextureRect(bounds);
}

void Vehicle::setTexture(const sf::Texture& texture, bool resetRect)
{
	m_sprite.setTexture(&texture, resetRect);
}

void Vehicle::setTextureRec(const sf::IntRect& bounds)
{
	m_sprite.setTextureRect(bounds);
}

void Vehicle::setSize(const sf::Vector2f& size)
{
	m_sprite.setSize(size);
	Collision::setSize(size);
}

//scale texture and collision size
void Vehicle::setScale(const sf::Vector2f& scale)
{
	m_sprite.setScale(scale);
	//set Collision size to match Sprite size
	const auto& spriteSize = m_sprite.getSize();
	const auto& spriteScale = m_sprite.getScale();
	Collision::setSize({ spriteSize.x * spriteScale.x,spriteSize.y * spriteScale.y });
}

void Vehicle::draw(sf::RenderTarget& render) const
{
	render.draw(m_sprite);
}

void Vehicle::move(float speed)
{
	m_sprite.move(speed, 0);//limit speed max
}

Car::Car(sf::Vector2f pos, const sf::Texture& texture)
	: Vehicle(pos, texture)
{}

Car::Car(sf::Vector2f pos, const sf::Texture& texture, sf::IntRect textureBound)
	: Vehicle(pos, texture, textureBound)
{}
Truck::Truck(sf::Vector2f pos, const sf::Texture& texture)
	: Vehicle(pos, texture)
{}

Truck::Truck(sf::Vector2f pos, const sf::Texture& texture, sf::IntRect textureBound)
	: Vehicle(pos, texture, textureBound)
{}
