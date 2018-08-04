/*!
 * \file Window.cpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief Windowクラスの実装
 */
#include<Window.hpp>

#include<ncurses.h>

Window::Window() : win_(NULL)
{
    win_ = initscr();
    noecho();
    curs_set(FALSE);

    return;
}

Window::~Window()
{
    endwin();

    return;
}

WINDOW* Window::get_raw() const
{
    return win_;
}

