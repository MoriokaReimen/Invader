#pragma once
#include<Screen.hpp>

enum OBJECT_TYPE
{
    FIELD,
    PLAYER,

    OBJECT_TYPE_COUNT
};

class GameObject
{
    int x_, y_;
    OBJECT_TYPE type;
    GameObject();

public:
    GameObject(const int& x, const int& y);
    GameObject(const GameObject& other);
    virtual ~GameObject();
    virtual void update() = 0;
    virtual void draw(Screen& screen);
};
