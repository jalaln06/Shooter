#include "view.h"
#include <iostream>

shooter::View::View(const sf::Vector2f &initialScreenSize) : m_circle(40), m_screenSize{initialScreenSize}
{
    m_circle.setFillColor(sf::Color::Cyan);
}

void shooter::View::update()
{
    m_fpsCounter.update();
}

void shooter::View::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_circle);
    target.draw(m_fpsCounter);
}

void shooter::View::setBounds(float width, float height)
{
    m_screenSize.x = width;
    m_screenSize.y = height;
}

void shooter::View::moveShip(Movements dir, float step)
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

    sf::Vector2f pos = m_circle.getPosition() + shift;
    pos.x = std::max(std::min(pos.x, m_screenSize.x - m_circle.getRadius() * 2), 0.0f);
    pos.y = std::max(std::min(pos.y, m_screenSize.y - m_circle.getRadius() * 2), 0.0f);
    m_circle.setPosition(pos);
    std::cout << m_circle.getPosition().x << "     " << m_circle.getPosition().y << '\n';
}
