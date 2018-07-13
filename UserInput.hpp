#pragma once
#include<Window.hpp>

typedef struct _win_st WINDOW;

class UserInput
{
    WINDOW* win_;
    UserInput();
    UserInput& operator=(const UserInput& other);
public:
    UserInput(Window& window);
    ~UserInput();
    char get();
};
