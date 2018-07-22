#include<Screen.hpp>
#include<Window.hpp>
#include<GameSystem.hpp>

#include<ncurses.h>
#include<string>

const int SCREEN_X(250);
const int SCREEN_Y(150);

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

bool Screen::print(const char* const str, const int& x, const int& y)
{
    int err = mvwprintw(win_, y, x, str);
    return err == OK;
}

bool Screen::print(const std::string& str, const int& x, const int& y)
{
    return this->print(str.c_str(), x, y);
}

bool Screen::print(const char& ch, const int& x, const int& y)
{
    return mvwaddch(win_, y, x, ch);
}

void Screen::printBorder(const int& x_size, const int& y_size)
{
    /*四隅を描画*/
    this->print("+", 0, 0);
    this->print("+", 0, y_size - 1);
    this->print("+", x_size - 1, y_size - 1);
    this->print("+", x_size - 1, 0);

    /*縦を描画*/
    for(int col = 1; col < x_size - 1; col++) {
        this->print("-", col, 0);
        this->print("-", col, y_size - 1);
    }

    /*横を描画*/
    for(int row = 1; row < y_size - 1; row++) {
        this->print("|", 0, row);
        this->print("|", x_size - 1, row);
    }

    return;
}

void Screen::getSize(int& x, int& y)
{
    getmaxyx(win_, max_y_, max_x_);
    x = this->max_x_;
    y = this->max_y_;
    return;
}

void Screen::drawObjects()
{
    Field* field = GameSystem::getField();
    for(auto it = field->objects.begin();
        it != field->objects.end();
        it++)
    {
        (*it)->draw(*this);
    }

    return;
}
