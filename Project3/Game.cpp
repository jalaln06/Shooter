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

void Game::togglemove(char move){
	sf::Vector2f pos;
	switch (move)
	{
	case 'w':
		pos = mycircle.getPosition();
		mycircle.setPosition(pos.x, pos.y - 10);
		break;
	case 's':
		pos = mycircle.getPosition();
		mycircle.setPosition(pos.x, pos.y + 10);
		break;
	case 'a':
		pos = mycircle.getPosition();
		mycircle.setPosition(pos.x-10, pos.y);
		break;
	case 'd':
		pos = mycircle.getPosition();
		mycircle.setPosition(pos.x+10, pos.y);
		break;
	}
}
