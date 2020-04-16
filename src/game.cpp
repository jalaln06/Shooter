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

void Game::moveShip(Movements dir, float step)
{
    sf::Vector2f shift(0, 0);
    switch (dir)
    {
        case Movements::UP:
            shift.y -= step;
            break;
        case Movements::DOWN:
            shift.y += step;
            break;
        case Movements::LEFT:
            shift.x -= step;
            break;
        case Movements::RIGHT:
            shift.x += step;
            break;
    }
    mycircle.setPosition(mycircle.getPosition() + shift);
}
