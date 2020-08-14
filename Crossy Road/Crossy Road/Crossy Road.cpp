<<<<<<< Updated upstream
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include <iostream>

#include "Collider.h"


int main()
{
	//FixConsoleWindow();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Oh wow!");
	sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
	shape.setFillColor(sf::Color::Blue);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setFillColor(sf::Color::Green);

	int x = 400, y = 500;
	shape.setPosition(400, 200);
	player.setPosition(x, y);
	window.setKeyRepeatEnabled(false);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				if (event.text.unicode < 128) {
					std::cout << event.text.unicode << std::endl;
				}
			case sf::Event::KeyPressed:
				switch (event.key.code) {
				case (sf::Keyboard::Up): {
					y -= 50;
					player.setPosition(x, y);
					break;
				}
				case (sf::Keyboard::Down): {
					y += 50;
					player.setPosition(x, y);
					break;
				}
				case (sf::Keyboard::Left): {
					x -= 50;
					player.setPosition(x, y);
					break;
				}
				case (sf::Keyboard::Right): {
					x += 50;
					player.setPosition(x, y);
					break;
				}
				case sf::Event::KeyReleased:
					break;
				}
			}
		}

		Collider col(player);
		Collider col2(shape);
		col.CheckCollision(col2, 1.0f);

		window.clear();
		window.draw(shape);
		

		window.draw(player);
		window.display();
	}

=======
//#include <SFML/Graphics.hpp>
//#include <SFML/System.hpp>
//#include <Windows.h>
//#include <iostream>
//#include "RigidBody.h"
//#include "Collider.h"
//#include "Player.h"
//#include <time.h>
//#include "Enemy.h"
//#include "Spawner.h"
//int main()
//{
//	//FixConsoleWindow();
//	
//	srand(time(0));
//	sf::RenderWindow window(sf::VideoMode(800, 600), "Oh wow!");
//	sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
//	shape.setFillColor(sf::Color::Blue);
//	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
//	player.setFillColor(sf::Color::Green);
//	
//	int x = 400, y = 500;
//	shape.setPosition(400, 200);
//	player.setPosition(x, y);
//	window.setKeyRepeatEnabled(false);
//	float spawnTime = 50.f;
//	float maxTime = 50.f;
//
//	Spawner sp;
//	vector<Enemy*>enemies;
//	float spawnTimer = 50.f;
//	float spawnTimerMax = 50.f;
//	while (window.isOpen())
//	{
//		/*spawnTime += 1.f;
//		if (spawnTime >= maxTime) {
//			sp.Update(window,shape);
//			spawnTime = 0.f;
//		}*/
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			switch (event.type) {
//			case sf::Event::Closed:
//				window.close();
//			case sf::Event::TextEntered:
//				if (event.text.unicode < 128) {
//					std::cout << event.text.unicode << std::endl;
//				}
//			case sf::Event::KeyPressed:
//				switch (event.key.code) {
//				case (sf::Keyboard::Up): {
//					y -= 50;
//					player.setPosition(x, y);
//					break;
//				}
//				case (sf::Keyboard::Down): {
//					y += 50;
//					player.setPosition(x, y);
//					break;
//				}
//				case (sf::Keyboard::Left): {
//					x -= 50;
//					player.setPosition(x, y);
//					break;
//				}
//				case (sf::Keyboard::Right): {
//					x += 50;
//					player.setPosition(x, y);
//					break;
//				}
//				case sf::Event::KeyReleased:
//					break;
//				}
//			}
//		}
//		Collider col(player);
//		Collider col2(shape);
//		col.CheckCollision(col2, 1.0f);
//	
//		window.clear();
//		window.draw(shape);
//	
//		
//		window.draw(player);
//		window.display();
//	}
//
//	return 0;
//}
#include "Game.h"
int main() {
	Game game;
	game.run();
>>>>>>> Stashed changes
	return 0;
}