#include<Screen.hpp>
#include<Window.hpp>

#include<ncurses.h>
#include<string>

Screen::Screen(const Window& win) : win_(NULL), max_x_(0), max_y_(0)
{
  win_ = win.get_raw();
  getmaxyx(win_, max_y_, max_x_);
  return;
}

Screen::~Screen()
{
    return;
}

void Screen::clear()
{
    wclear(win_);
    return;
}

void Screen::update()
{
    wrefresh(win_);
    return;
}

bool Screen::print(const char* const ch, const int& x, const int& y)
{
    int err = mvwprintw(win_, y, x, ch);
    return err == OK;
}

bool Screen::print(const std::string& str, const int& x, const int& y)
{
    return this->print(str.c_str(), x, y);
}

void Screen::getSize(int& x, int& y)
{
    x = this->max_x_;
    y = this->max_y_;
    return;
}
