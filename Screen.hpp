#pragma once

#include<string>

enum DISP_TYPE
{
    PLAYER,
    ENEMY,
    LASER,
    EXPLOSION,

    DISP_TYPE_COUNT
};


struct Position
{
    int x;
    int y;
};

struct DispData
{
    Position pos;
    DISP_TYPE type;
};

typedef struct _win_st WINDOW;
class Window;

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
    bool print(const char* const ch, const int& x, const int& y);
    bool print(const std::string& str, const int& x, const int& y);
    void getSize(int& x, int& y);
};
