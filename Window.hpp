#pragma once
#include<ncurses.h>

class Window
{
    WINDOW* win_;
    Window& operator=(const Window& other);
    Window(const Window& other);
public:
    Window();
    ~Window();
    WINDOW* get_raw() const;
};
