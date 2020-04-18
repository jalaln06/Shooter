#ifndef SHOOTER_GAME
#define SHOOTER_GAME

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "fps.h"

enum class Movements
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Game
{
protected:
    sf::CircleShape mycircle;
    sf::Vector2f screenSize;
    FpsCounter myCounter;
public:
    explicit Game(const sf::Vector2f &initialScreenSize);

    void draw(sf::RenderTarget &target);

    void moveShip(Movements dir, float step = DEFAULT_STEP);

    void setBounds(float width, float height);
};

#endif