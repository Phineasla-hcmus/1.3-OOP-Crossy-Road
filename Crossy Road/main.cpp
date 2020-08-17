#include"Framework/game.h"
#include<iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setFramerateLimit(200);
    sf::Clock clock;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Image icon;
    icon.loadFromFile("D:/GitHub/HK3-OOP-Crossy-Road/Crossy Road/Resource/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        std::cout << 1.f / clock.restart().asSeconds() << std::endl;
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}