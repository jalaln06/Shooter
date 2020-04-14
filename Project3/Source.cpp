#include <SFML/Graphics.hpp>
#include "Game.h"
int main() {
	sf::RenderWindow window(sf::VideoMode(400, 600), "Shooter");
	window.setFramerateLimit(60);
	Game myclass;
	while (window.isOpen()) {	
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
				if (event.key.code == sf::Keyboard::O) {
					myclass.togglecircle();
				}
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.draw(myclass);
		window.display();
	}
	return 0;
}