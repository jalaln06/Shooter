#ifndef SHOOTER_FPS_H
#define SHOOTER_FPS_H

#include "SFML/Graphics.hpp"

class FpsCounter : public sf::Drawable
{
public:
    FpsCounter();

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Text m_fpsHelpText;
    sf::Text m_fpsText;
    sf::Clock m_timer;
    float m_fps;
};


#endif //SHOOTER_FPS_H
