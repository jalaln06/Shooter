

#ifndef SHOOTER_GAME_VIEW_H
#define SHOOTER_GAME_VIEW_H

#include "view.h"
#include <iostream>

namespace shooter
{
    class GameView : public View
    {
    private:
        sf::ConvexShape m_ship;
    public:
        explicit GameView(Game &game);

        void CreateShip();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        void update() override;

        void processKey(sf::Event::KeyEvent const &key) override;
    };
}

#endif //SHOOTER_GAME_VIEW_H
