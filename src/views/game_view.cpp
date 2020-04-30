
#include "game_view.h"
#include "../game.h"
#include "menu_view.h"
shooter::GameView::GameView(Game& game)
        : View("game", game)
{
}

void shooter::GameView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_ship);
}

void shooter::GameView::update()
{
}

void shooter::GameView::processKey(const sf::Event::KeyEvent &key)
{
    if (key.code == sf::Keyboard::Escape)
    {
        m_game.setView(std::make_unique<MenuView>(m_game));
    }
    else
    {
        std::cout << "Pressed unsupported key in game: " << key.code << std::endl;
    }
}

void shooter::GameView::CreateShip()
{
    m_ship.setPointCount(9);
    m_ship.setPoint(0,sf::Vector2f(30, 20));
    m_ship.setPoint(1,sf::Vector2f(45, 30));
    m_ship.setPoint(2,sf::Vector2f(45, 100));
    m_ship.setPoint(3,sf::Vector2f(70, 100));
    m_ship.setPoint(4,sf::Vector2f(85, 120));
    m_ship.setPoint(5,sf::Vector2f(-25, 120));
    m_ship.setPoint(6,sf::Vector2f(-10, 100));
    m_ship.setPoint(7,sf::Vector2f(15, 100));
    m_ship.setPoint(8,sf::Vector2f(15, 30));
    m_ship.setFillColor(sf::Color::Red);
    m_ship.setPosition();
}
