#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>
#include <ctime>
const char *title = "Shooter";

int main()
{
    sf::VideoMode origin = sf::VideoMode::getDesktopMode();
    sf::VideoMode hd = *std::find_if(
            std::begin(sf::VideoMode::getFullscreenModes()),
            std::end(sf::VideoMode::getFullscreenModes()),
            [&origin](const sf::VideoMode& mode){
                return mode.width == 1280 && mode.height == 720 && mode.bitsPerPixel == origin.bitsPerPixel;
            }
    );

    sf::RenderWindow window(origin, title);
    window.setFramerateLimit(60);
    Game game(sf::Vector2f(window.getSize()));
    sf::CircleShape c(10);
    c.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;

                    case sf::Keyboard::F:
                        window.close();
                        window.create(hd, title);
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
        window.draw(c);
        window.display();
    }

    return 0;
}
