#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 600), "Shooter");
    window.setFramerateLimit(60);

    Game game{};

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

                    case sf::Keyboard::O:
                        game.togglecircle();
                        break;

                    case sf::Keyboard::W:
                    case sf::Keyboard::Up:
                        game.togglemove('w');
                        break;

                    case sf::Keyboard::S:
                    case sf::Keyboard::Down:
                        game.togglemove('s');
                        break;

                    case sf::Keyboard::A:
                    case sf::Keyboard::Left:
                        game.togglemove('a');
                        break;

                    case sf::Keyboard::D:
                    case sf::Keyboard::Right:
                        game.togglemove('d');
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
