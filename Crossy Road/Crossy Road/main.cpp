#include"main.h"
#include<vector>
#include"framework/util/random.h"
#include"framework/util/res_manager.h"
//int main() {
//	res_manager<sf::Texture> res("test");
//	res.get("test.png");
//}
int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Cursy Road", sf::Style::Close);
	sf::RectangleShape shape(sf::Vector2f(100,100));
	std::vector<sf::RectangleShape> car_vec;
	srand(time(0));
	for (size_t i = 0; i < 3; ++i) {
		float size = rand() % (100 - 50 + 1) + 50;
		car_vec.push_back(sf::RectangleShape(sf::Vector2f(size, size)));
	}
	window.setKeyRepeatEnabled(false);
	//shape.setFillColor(sf::Color::Blue);	
	res_manager<sf::Texture> res("textures");
	shape.setTexture(&res.get("player", "png"));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				shape.move(-100, 0);
				break;
			case sf::Keyboard::Right:
				shape.move(100, 0);
				break;
			case sf::Keyboard::Up:
				shape.move(0, -100);
				break;
			case sf::Keyboard::Down:
				shape.move(0, 100);
				break;
			default:
				break;
			}
		}
		
		}
		window.clear();
		window.draw(shape);
		car_vec[0].move(0.1f, 0);
		window.draw(car_vec[0]);
		//car_vec[1].move(0, 0.01f);
		window.draw(car_vec[1]);
		window.display();
	}
	return 0;
}