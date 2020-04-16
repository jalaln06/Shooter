#include "game.h"

Game::Game() : need_draw{false}, mycircle(40)
{
    mycircle.setFillColor(sf::Color::Cyan);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (need_draw)
    {
        target.draw(mycircle);
    }
}

void Game::toggleCircle()
{
    need_draw = !need_draw;
}

void Game::moveShip(Movements dir)
{
    sf::Vector2f pos = mycircle.getPosition();
    switch (dir)
    {
        case Movements::UP:
            mycircle.setPosition(pos.x, pos.y - 10);
            break;
        case Movements::DOWN:
            mycircle.setPosition(pos.x, pos.y + 10);
            break;
        case Movements::LEFT:
            mycircle.setPosition(pos.x - 10, pos.y);
            break;
        case Movements::RIGHT:
            mycircle.setPosition(pos.x + 10, pos.y);
            break;
    }
}
