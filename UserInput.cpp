/*!
 * \file UserInput.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief UserInputクラスの実装
 */
#include<UserInput.hpp>

#include<GameSystem.hpp>
#include<InputKeep.hpp>

#include<ncurses.h>

UserInput::UserInput(Window& window)
{
    this->win_ = window.get_raw();
    nodelay(win_, true);
    return;
}

UserInput::~UserInput()
{
    /*NO OP*/
}

char UserInput::store()
{
    const char ch =  wgetch(win_);
    InputKeep* keep = GameSystem::getInputKeep();
    switch(ch) {
    case 'k':
        keep->store(UP);
        break;
    case 'j':
        keep->store(DOWN);
        break;
    case 'h':
        keep->store(RIGHT);
        break;
    case 'l':
        keep->store(LEFT);
        break;
    case 's':
        keep->store(SHOOT);
        break;
    case 'q':
        keep->store(GAME_END);
        break;
    }

    return ch;
}

