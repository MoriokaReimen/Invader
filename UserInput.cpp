#include<UserInput.hpp>
#include<GameSystem.hpp>

#include<ncurses.h>
#include<InputKeep.hpp>

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
    }

    return ch;
}

