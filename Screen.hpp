#pragma once

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

class Screen
{
    int max_x_;
    int max_y_;

    Screen(const Screen& other);
    Screen& operator=(const Screen& other);
public:
    Screen();
    ~Screen();
    void clear();
    void update();
    bool print(const char* const ch, const Position& pos);
    bool print(const char* const ch, const int& x, const int& y);
    void getSize(int& x, int& y);
};
