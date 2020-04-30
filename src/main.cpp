#include <SFML/Graphics.hpp>
#include "game.h"
#include "input_controller.h"

int main()
{
    const char *title = "Shooter";
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), title, sf::Style::None); //Creating standard window with name title
    window.setFramerateLimit(60);

    shooter::Game game(window); // Initializing class game with our window
    shooter::InputController input(window, game); // Sending window and game to the class that processes input

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event)) // if something happened we process
        {
            input.processEvent(event);
        }

        game.update();

        window.clear();
        window.draw(game);
        window.display();
    }

    return 0;
}
