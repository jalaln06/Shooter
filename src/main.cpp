#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
#include <ctime>
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Shooter");
    window.setFramerateLimit(60);
    Game game(sf::Vector2f(window.getSize()));

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::Resized)
            {
                const float w = static_cast<float>(event.size.width);
                const float h = static_cast<float>(event.size.height);
                window.setView(sf::View(sf::Vector2f(w / 2.0f, h / 2.0f), sf::Vector2f(w, h)));
                game.setBounds(w, h);
            } else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;

                    case sf::Keyboard::W:
                    case sf::Keyboard::Up:
                        game.moveShip(Movements::UP);
                        break;

                    case sf::Keyboard::S:
                    case sf::Keyboard::Down:
                        game.moveShip(Movements::DOWN);
                        break;

                    case sf::Keyboard::A:
                    case sf::Keyboard::Left:
                        game.moveShip(Movements::LEFT);
                        break;

                    case sf::Keyboard::D:
                    case sf::Keyboard::Right:
                        game.moveShip(Movements::RIGHT);
                        break;

                    default:
                        break;
                }
            }
        }

        window.clear();
        window.draw(game);
        window.display();
    }

    return 0;
}
