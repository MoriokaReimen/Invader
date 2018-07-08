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

