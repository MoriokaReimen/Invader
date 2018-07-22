#pragma once
#include<Screen.hpp>

class GameObject
{
protected:
    int x_;
    int y_;
    bool is_alive_;

public:
    GameObject();
    virtual ~GameObject() = 0;
    virtual void update() = 0;
    virtual void draw(Screen& screen) = 0;

    void getPosition(int& x, int& y);
    bool isAlive();

};
