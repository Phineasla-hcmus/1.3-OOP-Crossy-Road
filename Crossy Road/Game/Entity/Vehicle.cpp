#include "Vehicle.h"

//Vehicle::Vehicle(sf::Color color, sf::Vector2f position, sf::Vector2f size) :Collision(size.x, size.y)
//{
//	this->vehicle.setPosition(position);
//	this->vehicle.setSize(size);
//	this->vehicle.setFillColor(color);
//	//this->enemy.setOutlineColor(sf::Color::Green);
//	//this->enemy.setOutlineThickness(1.f);
//}
//
//Car::Car(sf::Vector2f position) :m_active(true), Vehicle(sf::Color::White, sf::Vector2f(20.f, 20.f), sf::Vector2f(90.f, 70.f)) {
//
//	this->vehicle.setSize(sf::Vector2f(90.f, 70.f));
//
//	this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));
//	this->vehicle.setFillColor(sf::Color::Blue);	
//
//};
//void Car::draw(sf::RenderTarget& target) {
//	target.draw(this->vehicle);
//}
//
//Vehicle* Car::newVehicle(sf::Vector2f origin_pos)
//{
//	return new Car(origin_pos);
//}
//
//Truck::Truck(sf::Vector2f position) : m_active(true),Vehicle(sf::Color::Yellow, sf::Vector2f(15.f, 15.f), sf::Vector2f(90.f, 90.f)) {
//	this->vehicle.setSize(sf::Vector2f(90.f, 90.f));
//	this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));
//	this->vehicle.setFillColor(sf::Color::Yellow);
//		
//};
//void Truck::draw(sf::RenderTarget& target) {
//	target.draw(this->vehicle);
//}
//
//Vehicle* Truck::newVehicle(sf::Vector2f origin_pos)
//{
//	return new Truck(origin_pos);
//}
//	
//Bird::Bird(sf::Vector2f position) :m_active(true),Vehicle(sf::Color::Yellow, sf::Vector2f(15.f, 15.f), sf::Vector2f(100.f, 50.f)) {
//	this->vehicle.setSize(sf::Vector2f(90.f, 50.f));
//	this->vehicle.setPosition(sf::Vector2f(position.x, position.y - this->vehicle.getSize().y / 2));
//	this->vehicle.setFillColor(sf::Color::Magenta);
//};
//void Bird::draw(sf::RenderTarget& target) {
//	target.draw(this->vehicle);
//}
//
//Vehicle* Bird::newVehicle(sf::Vector2f origin_pos)
//{
//	return new Bird(origin_pos);
//}

Vehicle::Vehicle(sf::Vector2f pos, const sf::Texture& texture)
	: Collision((float)texture.getSize().x, (float)texture.getSize().y)
	, m_sprite(sf::Vector2f((float)texture.getSize().x,(float)texture.getSize().y))
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

const sf::Vector2f& Vehicle::getPosition() const
{
	return m_sprite.getPosition();
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
	m_sprite.move(speed > 100 ? 100 : speed, 0);//limit speed max
//	std::cout << "move vehicle\n";
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
