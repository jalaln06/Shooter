#include "game.h"
#include <iostream>

Game::Game(const sf::Vector2f &initialScreenSize) : mycircle(40), screenSize{initialScreenSize}
{
    mycircle.setFillColor(sf::Color::Cyan);
}

void Game::draw(sf::RenderTarget &target)
{
    target.draw(mycircle);
    myCounter.draw(target);
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

    sf::Vector2f pos = mycircle.getPosition() + shift;
    pos.x = std::max(std::min(pos.x, screenSize.x-mycircle.getRadius()*2), 0.0f);
    pos.y = std::max(std::min(pos.y, screenSize.y-mycircle.getRadius()*2), 0.0f);
    mycircle.setPosition(pos);
    std::cout << mycircle.getPosition().x << "     " << mycircle.getPosition().y << '\n';
}

void Game::setBounds(float width, float height)
{
    screenSize.x = width;
    screenSize.y = height;
}
