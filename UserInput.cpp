#include<UserInput.hpp>

#include<ncurses.h>

UserInput::UserInput(Window& window)
{
    this->win_ = window.get_raw();
    return;
}

UserInput::~UserInput()
{
    /*NO OP*/
}

char UserInput::get()
{
    return wgetch(win_);
}

