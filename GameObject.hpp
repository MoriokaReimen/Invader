#pragma once
#include<Screen.hpp>

enum OBJECT_TYPE {
    PLAYER,
    ENEMY,
    BULLET
};

class GameObject
{
protected:
    double x_;
    double y_;
    bool is_alive_;
    OBJECT_TYPE type_;

public:
    GameObject(const int& x, const int& y, const OBJECT_TYPE& type);
    virtual ~GameObject() = 0;
    virtual void update() = 0;
    virtual void draw(Screen& screen) = 0;
    virtual void kill();

    void getPosition(int& x, int& y);
    bool isAlive();
    OBJECT_TYPE getType();
};
