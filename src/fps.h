#ifndef SHOOTER_FPS_H
#define SHOOTER_FPS_H

#include "SFML/Graphics.hpp"

class FpsCounter
{
public:
    FpsCounter();
    void draw(sf::RenderTarget &target);

private:
    sf::Font m_font;
    sf::Text m_fpsText;
    sf::Clock m_timer;
    float m_fps;
    int m_frames;
};

#endif //SHOOTER_FPS_H
