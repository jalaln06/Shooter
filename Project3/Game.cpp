#include "Game.h"

Game::Game() :need_draw{ false }, mycircle(40)
{
	mycircle.setFillColor(sf::Color::Cyan);
}

 void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (need_draw) {
		target.draw(mycircle);
	}
}

void Game::togglecircle()
{
	need_draw=!need_draw;
}
