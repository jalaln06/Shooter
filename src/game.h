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
    sf::CircleShape mycircle;
    sf::Vector2f screenSize;
public:
    explicit Game(const sf::Vector2f &initialScreenSize);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void moveShip(Movements dir, float step = DEFAULT_STEP);

    void setBounds(float width, float height);
};

#endif