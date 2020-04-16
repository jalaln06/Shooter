#ifndef SHOOTER_GAME
#define SHOOTER_GAME

#include <SFML/Graphics.hpp>
#include "constants.h"

enum class Movements
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Game : public sf::Drawable
{
protected:
    bool need_draw;
    sf::CircleShape mycircle;
public:
    Game();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void toggleCircle();
    void moveShip(Movements dir, float step = DEFAULT_STEP);
};

#endif