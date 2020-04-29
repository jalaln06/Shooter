#ifndef SHOOTER_VIEW
#define SHOOTER_VIEW

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
        FpsCounter& m_fpsCounter;
        const sf::Window& m_window;

    public:
        View(const sf::Window& window, FpsCounter& counter );

        void update() override;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void moveShip(Movements dir, float step = DEFAULT_STEP);

        void setBounds(float width, float height);
    };
}

#endif