/*!
 * \file UserInput.hpp
 *
 * \author MoriokaReimen
 * \date 2018.08.04
 * \brief UserInputクラスの宣言
 */
#pragma once
#include<Window.hpp>

const char ERR(-1);

typedef struct _win_st WINDOW;

class UserInput
{
    WINDOW* win_;
    UserInput();
    UserInput& operator=(const UserInput& other);
public:
    UserInput(Window& window);
    ~UserInput();
    char store();
};
