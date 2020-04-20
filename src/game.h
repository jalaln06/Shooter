
#ifndef SHOOTER_GAME_H
#define SHOOTER_GAME_H

#include<unordered_map>
#include "view.h"
#include <memory>

namespace shooter
{
    enum class Views
    {
        Game,
        Menu
    };

    class Game
    {
    private:
        std::unordered_map<Views, std::shared_ptr<View>> m_views;
        std::shared_ptr<View> m_currentView;
    public:
        explicit Game(std::shared_ptr<View> view);

        void setView(Views views);

        std::shared_ptr<View> view() const;
    };
}


#endif //SHOOTER_GAME_H
