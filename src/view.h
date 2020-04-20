#ifndef SHOOTER_GAME
#define SHOOTER_GAME

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "fps.h"

namespace shooter
{
    enum class Movements
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class View : public sf::Drawable, public Updateable
    {
    protected:
        sf::CircleShape m_circle;
        sf::Vector2f m_screenSize;
        FpsCounter m_fpsCounter;

    public:
        explicit View(const sf::Vector2f &initialScreenSize);

        void update() override;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void moveShip(Movements dir, float step = DEFAULT_STEP);

        void setBounds(float width, float height);
    };
}

#endif