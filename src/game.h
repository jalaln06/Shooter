#ifndef SHOOTER_GAME
#define SHOOTER_GAME

#include <SFML/Graphics.hpp>

class Game : public sf::Drawable
{
protected:
    bool need_draw;
    sf::CircleShape mycircle;
public:
    Game();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void togglecircle();

    virtual void togglemove(char move);
};

#endif