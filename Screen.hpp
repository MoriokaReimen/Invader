#pragma once

#include<string>

typedef struct _win_st WINDOW;
class Window;

enum COLOR
{
    PLAYER_COLOR,
    ENEMY_COLOR,
    BULLET_COLOR,
};

class Screen
{
    WINDOW* win_;
    int max_x_;
    int max_y_;

    Screen();
    Screen(const Screen& other);
    Screen& operator=(const Screen& other);
public:
    Screen(const Window& win);
    ~Screen();
    void clear();
    void update();
    bool print(const char* const str, const int& x, const int& y);
    bool print(const std::string& str, const int& x, const int& y);
    bool print(const char& ch, const int& x, const int& y);
    bool print(const char* const str, const int& x, const int& y, const COLOR& color);
    bool print(const std::string& str, const int& x, const int& y, const COLOR& color);
    bool print(const char& ch, const int& x, const int& y, const COLOR& color);
    void printBorder(const int& x_size, const int& y_size);
    void printBorder();
    void getSize(int& x, int& y);
    void drawObjects();
};
