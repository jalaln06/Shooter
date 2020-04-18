
#include "fps.h"

void FpsCounter::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_fpsHelpText);
}

void FpsCounter::update()
{

}

FpsCounter::FpsCounter()
{
//    m_fpsHelpText.move(5,5);
    m_fpsHelpText.setCharacterSize(16);
    m_fpsHelpText.setPosition(100,100);
    m_fpsHelpText.setOutlineColor(sf::Color::Green);
    m_fpsHelpText.setString("FPS: ");
    m_fpsHelpText.setFillColor(sf::Color::White);
    m_fpsHelpText.setOutlineThickness(2);
}
