#include <SFML/Graphics.hpp>
#include "view.h"
#include <iostream>
#include <ctime>

const char *title = "Shooter";

int main()
{
    sf::VideoMode origin = sf::VideoMode::getDesktopMode();
    sf::VideoMode hd = *std::find_if(
            std::begin(sf::VideoMode::getFullscreenModes()),
            std::end(sf::VideoMode::getFullscreenModes()),
            [&origin](const sf::VideoMode &mode)
            {
                return mode.width == 1280 && mode.height == 720 && mode.bitsPerPixel == origin.bitsPerPixel;
            }
    );
    for (auto &mode:sf::VideoMode::getFullscreenModes())
    {
        std::cout << mode.width << ' ' << mode.height << ' ' << mode.bitsPerPixel << '\n';
    }
    sf::RenderWindow window(origin, title);
    window.setFramerateLimit(60);
    shooter::View view(sf::Vector2f(window.getSize()));
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
                        view.moveShip(shooter::Movements::UP);
                        break;

                    case sf::Keyboard::S:
                    case sf::Keyboard::Down:
                        view.moveShip(shooter::Movements::DOWN);
                        break;

                    case sf::Keyboard::A:
                    case sf::Keyboard::Left:
                        view.moveShip(shooter::Movements::LEFT);
                        break;

                    case sf::Keyboard::D:
                    case sf::Keyboard::Right:
                        view.moveShip(shooter::Movements::RIGHT);
                        break;

                    default:
                        break;
                }
            }
        }

        view.update();

        window.clear();
        window.draw(view);
        window.display();
    }

    return 0;
}
