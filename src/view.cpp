#include "view.h"
#include <iostream>


shooter::View::View(const sf::Window &window, shooter::FpsCounter &counter) : m_window{window}, m_fpsCounter{counter}
{

}


void shooter::View::update()
{
    m_fpsCounter.update();
}

void shooter::View::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_fpsCounter);
}