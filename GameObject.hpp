#pragma once
#include<Screen.hpp>

class GameObject
{
    int x_, y_;
    GameObject();

public:
    GameObject(const int& x, const int& y);
    GameObject(const GameObject& other);
    virtual ~GameObject();
    virtual void update() = 0;
    virtual void draw(Screen& screen);
};
