#include<Screen.hpp>

#include<ncurses.h>
#include<unistd.h>
#include<string>

Screen::Screen()
{
  initscr();
  noecho();
  curs_set(FALSE);
  getmaxyx(stdscr, max_y_, max_x_);
  return;
}

Screen::~Screen()
{
    endwin();
    return;
}

void Screen::clear()
{
    wclear(stdscr);
    return;
}

void Screen::update()
{
    wrefresh(stdscr);
    return;
}

bool Screen::print(const char* const ch, const int& x, const int& y)
{
    int err = mvwprintw(stdscr, y, x, ch);
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
