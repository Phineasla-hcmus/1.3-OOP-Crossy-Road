<<<<<<< Updated upstream
#include"Framework/game.h"
int main()
{
    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    //sf::Image icon;
    //icon.loadFromFile("D:/GitHub/HK3-OOP-Crossy-Road/Crossy Road/Resource/icon.png");
    //window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    window.clear();
    //    window.draw(shape);
    //    window.display();
    //}

    //return 0;
=======
//#include"Framework/game.h"
//int main()
//{
//    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    //sf::CircleShape shape(100.f);
//    //shape.setFillColor(sf::Color::Green);
//    //sf::Image icon;
//    //icon.loadFromFile("D:/GitHub/HK3-OOP-Crossy-Road/Crossy Road/Resource/icon.png");
//    //window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//    //while (window.isOpen())
//    //{
//    //    sf::Event event;
//    //    while (window.pollEvent(event))
//    //    {
//    //        if (event.type == sf::Event::Closed)
//    //            window.close();
//    //    }
//
//    //    window.clear();
//    //    window.draw(shape);
//    //    window.display();
//    //}
//
//    //return 0;
//    game Game;
//    Game.run();
//}
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Collidable.h"
#include "Player.h"
#include <iostream>


int main()
{
    sf::RenderWindow mywindow(sf::VideoMode(800, 600), "title");
    sf::Event ev;
    mywindow.setFramerateLimit(60);
    mywindow.setKeyRepeatEnabled(false);
    Object obj(sf::Vector2f(50.f,50.f));

    Player player;
    player.myrect.setFillColor(sf::Color(255, 255, 0));
    while (mywindow.isOpen())
    {
        while (mywindow.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed) mywindow.close();
            player.keymove();
        }
        if (player.tryCollideWith(obj)) {
           std::cout << "Collided!" << std::endl;
        }
        player.moving();
        player.myrect.setPosition(player.x, player.y);

        mywindow.clear(sf::Color(0, 200, 0));
        mywindow.draw(player.myrect);
        mywindow.draw(obj.rect);
        mywindow.display();
    }
>>>>>>> Stashed changes
}