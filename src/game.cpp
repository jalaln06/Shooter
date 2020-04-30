
#include "game.h"
#include <utility>

#include "game.h"
#include "views/game_view.h"
#include "views/menu_view.h"


shooter::Game::Game(sf::Window &window)
        : m_window{window}, m_state{}, m_currentView{new MenuView(*this)}, m_fpsCounter{} //Constructor which initializes
{
}

void shooter::Game::update() //method to update all current things that needs drawing
{
    m_currentView->update();
    m_fpsCounter.update();
}

void shooter::Game::draw(sf::RenderTarget &target, sf::RenderStates states) const //function to draw
{
    target.draw(*m_currentView);
    target.draw(m_fpsCounter);
}

void shooter::Game::setView(std::unique_ptr<View> view)
{
    m_currentView = std::move(view);
}

sf::Window &shooter::Game::window()
{
    return m_window;
}

shooter::GameState &shooter::Game::state()
{
    return m_state;
}

void shooter::Game::processKey(const sf::Event::KeyEvent &key)
{
    m_currentView->processKey(key);
}